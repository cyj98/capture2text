#include <QAbstractNativeEventFilter>
#include <QDebug>
#include <QApplication>

#include "MouseHook.h"
#include "MacMouseMonitor.h"

#import <AppKit/AppKit.h>

class MouseEventFilter : public QAbstractNativeEventFilter
{
public:
    bool nativeEventFilter(const QByteArray &eventType, void *message, long *) {
        if (eventType == "mac_generic_NSEvent" || eventType == "NSEvent") {
            NSEvent *event = static_cast<NSEvent *>(message);
            switch ([event type]) {
                case NSEventTypeLeftMouseDown:
                    emit MouseHook::getInstance().buttonPressed(MouseHook::LEFT_MOUSE_DOWN);
//                    qDebug() << QString::fromNSString([event characters]);
                    return true;
    //            case NSEventTypeLeftMouseUp:
                case NSEventTypeRightMouseDown:
                    MouseHook::getInstance().setRightMouseButtonHeld(true);
                    emit MouseHook::getInstance().buttonPressed(MouseHook::RIGHT_MOUSE_DOWN);
//                    qDebug() << QString::fromNSString([event characters]);
                    return true;
                case NSEventTypeRightMouseUp:
                    MouseHook::getInstance().setRightMouseButtonHeld(false);
    //            case NSEventTypeOtherMouseDown:
    //            case NSEventTypeOtherMouseUp:
                default:
                    return false;
            }
        }
        return false;
    }
};

id monitorId = nil;
QSharedPointer<QAbstractNativeEventFilter> MouseMonitor::filter(new MouseEventFilter);

void MouseMonitor::startMonitor() {
    if (monitorId != nil) return;

    const int mask =
            NSEventMaskLeftMouseDown |
//            NSEventMaskLeftMouseUp |
            NSEventMaskRightMouseDown | NSEventMaskRightMouseUp ;
//            NSEventMaskOtherMouseDown | NSEventMaskOtherMouseUp |
//            NSEventMaskAppKitDefined | NSEventMaskSystemDefined;
    // The global monitoring handler is *not* called for events sent to our application
    monitorId = [NSEvent addGlobalMonitorForEventsMatchingMask:mask handler:^(NSEvent* event) {
        filter->nativeEventFilter("NSEvent", event, 0);
    }];
    // We also need to handle events coming to our application
    qApp->installNativeEventFilter(filter.data());
};

void MouseMonitor::stopMonitor() {
    if (monitorId == nil) return;
    [NSEvent removeMonitor:monitorId];
    monitorId = nil;
    qApp->removeNativeEventFilter(filter.data());
};
