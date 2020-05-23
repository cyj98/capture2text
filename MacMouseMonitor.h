#ifndef MACMOUSEMONITOR_H
#define MACMOUSEMONITOR_H

class MouseMonitor {
public:
    static MouseMonitor& getInstance()
    {
        static MouseMonitor instance;
        return instance;
    }
    void startMonitor();
    void stopMonitor();
};


#endif // MACMOUSEMONITOR_H
