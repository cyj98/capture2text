#ifndef MACMOUSEMONITOR_H
#define MACMOUSEMONITOR_H

#include <QAbstractNativeEventFilter>
#include <QSharedPointer>

class MouseMonitor {
public:
    static MouseMonitor& getInstance()
    {
        static MouseMonitor instance;
        return instance;
    }
    void startMonitor();
    void stopMonitor();
private:
    static bool isMonitoring;
    static QSharedPointer<QAbstractNativeEventFilter> filter;
};


#endif // MACMOUSEMONITOR_H
