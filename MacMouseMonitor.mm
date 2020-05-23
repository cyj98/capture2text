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
        if (eventType == "mac_generic_NSEvent") {
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

id monitorId;
QSharedPointer<QAbstractNativeEventFilter> filter(new MouseEventFilter);
bool isMonitoring = false;

void MouseMonitor::startMonitor() {
//    QSharedPointer<QAbstractNativeEventFilter> filter = QSharedPointer<QAbstractNativeEventFilter>(new MouseEventFilter);
    const int mask =
            NSEventMaskLeftMouseDown |
//            NSEventMaskLeftMouseUp |
            NSEventMaskRightMouseDown | NSEventMaskRightMouseUp;
//            NSEventMaskOtherMouseDown | NSEventMaskOtherMouseUp;
    // The global monitoring handler is *not* called for events sent to our application
    monitorId = [NSEvent addGlobalMonitorForEventsMatchingMask:mask handler:^(NSEvent* event) {
        filter->nativeEventFilter("NSEvent", event, 0);
    }];
    // We also need to handle events coming to our application
    qApp->installNativeEventFilter(filter.data());
    isMonitoring = true;
};

void MouseMonitor::stopMonitor() {
//    qDebug() << monitorId;
    if (isMonitoring == true) {
        isMonitoring = false;
        [NSEvent removeMonitor:monitorId];
        qApp->removeNativeEventFilter(filter.data());
    }
};
