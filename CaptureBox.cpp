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
#include "CaptureBox.h"
//#include "KeyboardHook.h"
#include "QHotkeyHook.h"
#include "MouseHook.h"
#ifdef Q_OS_MACOS
#include "MacMouseMonitor.h"
#endif

CaptureBox::CaptureBox()
    : QWidget(0, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Dialog | Qt::Tool),
      timerUpdateCaptureMode(this),
      captureModeLastPt(-1, -1),
      useBackgroundColor(true),
      backgroundColor(QColor(255, 0, 0, 64)),
      useBorder(true),
      borderColor(QColor(255, 0, 0, 255)),
      autoCaptureTimer(this),
      dragPosition(0, 0),
      moveTimer(this)
{
    setAttribute(Qt::WA_TranslucentBackground);

    setFixedSize(1, 1);
    connect(&timerUpdateCaptureMode, &QTimer::timeout, this, &CaptureBox::updateCaptureMode);
    connect(&autoCaptureTimer, &QTimer::timeout, this, &CaptureBox::autoCaptureTimeout);
    connect(&moveTimer, &QTimer::timeout, this, &CaptureBox::moveTimeout);
//    connect(&KeyboardHook::getInstance(), &KeyboardHook::keyPressed, this, &CaptureBox::hotkeyPressed);
    connect(&QHotkeyHook::getInstance(), &QHotkeyHook::keyPressed, this, &CaptureBox::hotkeyPressed, Qt::UniqueConnection);
    connect(&MouseHook::getInstance(), &MouseHook::buttonPressed, this, &CaptureBox::hotkeyPressed);
}

CaptureBox::~CaptureBox()
{

}

void CaptureBox::startCaptureMode()
{
#ifdef Q_OS_MACOS
    MouseMonitor::getInstance().startMonitor();
#endif
    MouseHook::getInstance().start();
//    MouseMonitor::getInstance().start();
//    KeyboardHook::getInstance().addHotkey(CANCEL, Hotkey("Esc"));
//    KeyboardHook::getInstance().addHotkey(CAPTURE, Hotkey("Enter"));
//    KeyboardHook::getInstance().addHotkey(LEFT, Hotkey("Left"));
//    KeyboardHook::getInstance().addHotkey(RIGHT, Hotkey("Right"));
//    KeyboardHook::getInstance().addHotkey(UP, Hotkey("Up"));
//    KeyboardHook::getInstance().addHotkey(DOWN, Hotkey("Down"));

    QHotkeyHook::getInstance().addHotkey(CANCEL, Qt::Key_Escape);
    QHotkeyHook::getInstance().addHotkey(CAPTURE, Qt::Key_Return);
    QHotkeyHook::getInstance().addHotkey(CAPTURE2, Qt::Key_Space);
    QHotkeyHook::getInstance().addHotkey(LEFT, Qt::Key_Left);
    QHotkeyHook::getInstance().addHotkey(RIGHT, Qt::Key_Right);
    QHotkeyHook::getInstance().addHotkey(UP, Qt::Key_Up);
    QHotkeyHook::getInstance().addHotkey(DOWN, Qt::Key_Down);

    QPoint startPt = QCursor::pos();
    QPoint windowStartPt = startPt;

    captureModePivot = startPt;
    windowStartPt.setX(startPt.x());
    windowStartPt.setY(startPt.y());
    move(windowStartPt);
    setFixedSize(1, 1);
    show();
    raise();
    updateCaptureMode();

    timerUpdateCaptureMode.start(captureModeUpdateMilliSec);
}

void CaptureBox::endCaptureMode()
{
    MouseHook::getInstance().endThread();
#ifdef Q_OS_MACOS
    MouseMonitor::getInstance().stopMonitor();
#endif
//    MouseMonitor::getInstance().endThread();
//    KeyboardHook::getInstance().removeHotkey(CANCEL);
//    KeyboardHook::getInstance().removeHotkey(CAPTURE);
//    KeyboardHook::getInstance().removeHotkey(LEFT);
//    KeyboardHook::getInstance().removeHotkey(RIGHT);
//    KeyboardHook::getInstance().removeHotkey(UP);
//    KeyboardHook::getInstance().removeHotkey(DOWN);
    QHotkeyHook::getInstance().removeHotkey(CANCEL);
    QHotkeyHook::getInstance().removeHotkey(CAPTURE);
    QHotkeyHook::getInstance().removeHotkey(CAPTURE2);
    QHotkeyHook::getInstance().removeHotkey(LEFT);
    QHotkeyHook::getInstance().removeHotkey(RIGHT);
    QHotkeyHook::getInstance().removeHotkey(UP);
    QHotkeyHook::getInstance().removeHotkey(DOWN);

    moveTimer.stop();
    timerUpdateCaptureMode.stop();
    captureModeLastPt.setX(-1);
    captureModeLastPt.setY(-1);
    hide();
}

void CaptureBox::hotkeyPressed(int id)
{
    if(id == MouseHook::LEFT_MOUSE_DOWN)
    {
        emit captured();
    }
    else if(id == MouseHook::RIGHT_MOUSE_DOWN)
    {
        moveCaptureBoxSize = QSize(width(), height());
    }
    else if(id == CANCEL)
    {
        endCaptureMode();
        emit cancel();
    }
    else if(id == CAPTURE)
    {
        emit captured();
    }
    else if(id == CAPTURE2)
    {
        emit captured();
    }
    else if(id == LEFT)
    {
        move(x() - 1, y());
        captureModePivot.setX(x());
        startMoveTimer();
        emit moved();
    }
    else if(id == RIGHT)
    {
        move(x() + 1, y());
        captureModePivot.setX(x());
        startMoveTimer();
        emit moved();
    }
    else if(id == UP)
    {
        move(x(), y() - 1);
        captureModePivot.setY(y());
        startMoveTimer();
        emit moved();
    }
    else if(id == DOWN)
    {
        move(x(), y() + 1);
        captureModePivot.setY(y());
        startMoveTimer();
        emit moved();
    }
//    else if(id == Qt::Key_Cancel)
//    {
//        endCaptureMode();
//        emit cancel();
//    }
//    else if(id == Qt::Key_Left)
//    {
//        move(x() - 1, y());
//        captureModePivot.setX(x());
//        startMoveTimer();
//        emit moved();
//    }
//    else if(id == Qt::Key_Right)
//    {
//        move(x() + 1, y());
//        captureModePivot.setX(x());
//        startMoveTimer();
//        emit moved();
//    }
//    else if(id == Qt::Key_Up)
//    {
//        move(x(), y() - 1);
//        captureModePivot.setY(y());
//        startMoveTimer();
//        emit moved();
//    }
//    else if(id == Qt::Key_Down)
//    {
//        move(x(), y() + 1);
//        captureModePivot.setY(y());
//        startMoveTimer();
//        emit moved();
//    }
}

void CaptureBox::updateCaptureMode()
{
    if(isVisible())
    {
        // Keep above other windows
        raise();
    }

    QPoint ptCursor = QCursor::pos();

    if(isVisible() && (captureModeLastPt != ptCursor))
    {
        startMoveTimer();
        captureModeLastPt = ptCursor;
        int x = ptCursor.x();
        int y = ptCursor.y();
        int x1 = x;
        int y1 = y;
        int x2 = x;
        int y2 = y;

        bool moveBothCorners = false;

//        bool moveBothCorners = MouseHook::getInstance().getRightMouseButtonHeld();

        if(x < captureModePivot.x())
        {
            x1 = x;

            if(moveBothCorners)
            {
                captureModePivot.setX(x1 + moveCaptureBoxSize.width());
            }

            x2 = captureModePivot.x();
        }
        else
        {
            x2 = x;

            if(moveBothCorners)
            {
                captureModePivot.setX(x2 - moveCaptureBoxSize.width());
            }

            x1 = captureModePivot.x();
        }

        if(y < captureModePivot.y())
        {
            y1 = y;

            if(moveBothCorners)
            {
                captureModePivot.setY(y1 + moveCaptureBoxSize.height());
            }

            y2 = captureModePivot.y();
        }
        else
        {
            y2 = y;

            if(moveBothCorners)
            {
                captureModePivot.setY(y2 - moveCaptureBoxSize.height());
            }

            y1 = captureModePivot.y();
        }

        if(x2 - 1 < x1)
        {
            x2 = x1 + 1;
        }

        if(y2 - 1 < y1)
        {
            y2 = y1 + 1;
        }

        setFixedSize(x2 - x1, y2 - y1);
        move(x1, y1);

        emit moved();
    }
}

void CaptureBox::startMoveTimer()
{
    moveTimer.start(moveTimeoutMilliSec);
}

void CaptureBox::autoCapture(QRect &rect)
{
    setFixedSize(rect.width() + 2, rect.height() + 2);
    move(rect.x() - 1, rect.y() - 1);
    show();
    raise();
    autoCaptureTimer.start(500);
}

QRect CaptureBox::getCaptureRect()
{
    QRect captureRect(x() + 1, y() + 1, width() - 2, height() - 2);
    return captureRect;
}

void CaptureBox::autoCaptureTimeout()
{
    autoCaptureTimer.stop();
    hide();
}

void CaptureBox::moveTimeout()
{
    moveTimer.stop();
    emit stoppedMoving();
}

void CaptureBox::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    // Draw the capture box rect
    if(useBackgroundColor)
    {
        painter.fillRect(0, 0, width(), height(), backgroundColor);
    }

    if(useBorder)
    {
        // Draw border around capture box rect
        QPen pen;
        pen.setColor(borderColor);
        painter.setPen(pen);
        painter.drawRect(0, 0, width() - 1, height() - 1);
    }
}
