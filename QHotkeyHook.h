#ifndef QHOTKEYHOOK_H
#define QHOTKEYHOOK_H

#include <QHotkey>
#include <QThread>
#include <QEventLoop>
//#include <QDebug>
#include <QMap>
#include <QKeySequence>

class QHotkeyHook : public QThread
{
    Q_OBJECT
public:
    void run();

    static QHotkeyHook& getInstance()
    {
        static QHotkeyHook instance;
        return instance;
    }

    QMap<int, QHotkey*> getHotkeys() { return hotkeys; }

    void addHotkey(int id, QKeySequence hotkey);
    void addHotkey(int id, Qt::Key hotkey);
    void removeHotkey(int id);

    void endThread();

signals:
    void keyPressed(int id);

private:
    QMap<int, QHotkey*> hotkeys;
};

#endif // QHOTKEYHOOK_H
