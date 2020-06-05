#include "QHotkeyHook.h"
#include <QDebug>
#ifndef CLI_BUILD
    #include <QApplication>
#else
    #include <QCoreApplication>
#endif

void QHotkeyHook::run()
{
    QEventLoop eventLoop;
    eventLoop.exec();
}

void QHotkeyHook::addHotkey(int id, QKeySequence hotkey)
{
    auto qhotkey = new QHotkey(hotkey, true, qApp);
    if(hotkeys.contains(id))
    {
        delete hotkeys[id];
        hotkeys.remove(id);
    }
    connect(qhotkey, &QHotkey::activated, this, [=](){
        emit this->keyPressed(id);
    });
    hotkeys.insert(id, qhotkey);
}

void QHotkeyHook::addHotkey(int id, Qt::Key hotkey)
{
    auto qhotkey = new QHotkey(hotkey, Qt::NoModifier, true, qApp);
    if(hotkeys.contains(id))
    {
        delete hotkeys[id];
        hotkeys.remove(id);
    }
    connect(qhotkey, &QHotkey::activated, this, [=](){
        emit this->keyPressed(id);
    });
    hotkeys.insert(id, qhotkey);
}

void QHotkeyHook::removeHotkey(int id)
{
    if(hotkeys.contains(id))
    {
        delete hotkeys[id];
        hotkeys.remove(id);
    }
}

void QHotkeyHook::endThread()
{
    for(auto id : hotkeys.keys())
    {
        delete hotkeys[id];
//        hotkeys.remove(id);
    }
    this->disconnect();
    exit(0);
}
