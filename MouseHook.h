/*
Copyright (C) 2010-2017 Christopher Brochtrup

This file is part of Capture2Text.

Capture2Text is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Capture2Text is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Capture2Text.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MOUSEHOOK_H
#define MOUSEHOOK_H

#include <QThread>
#include <QEventLoop>
#include <QDebug>
#include <QMap>
#ifdef Q_OS_WIN
//#include "Windows.h"
#endif

class MouseHook : public QThread
{
    Q_OBJECT
public:
    void run();

    static const int LEFT_MOUSE_DOWN = 1;
    static const int RIGHT_MOUSE_DOWN = 3;

    static MouseHook& getInstance()
    {
        static MouseHook instance;
        return instance;
    }
#ifdef Q_OS_WIN
//    HHOOK getHHook() const { return hHook; }
#endif

    void setRightMouseButtonHeld(bool held);
    bool getRightMouseButtonHeld();

    void endThread();

signals:
    void buttonPressed(int id);

private:
    bool rightMouseButtonHeld;

#ifdef Q_OS_WIN
    HHOOK hHook;
    bool scribbling = false;

    MouseHook(): hHook(nullptr), rightMouseButtonHeld(false)
    {

    }

    static LRESULT CALLBACK hookProc(int nCode, WPARAM wParam, LPARAM lParam);
#endif
};

#endif // MOUSEHOOK_H
