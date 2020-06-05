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

#include <QGuiApplication>
#include <QPixmap>
#include <QDebug>
#include <QWidget>
#include <QScreen>
#include "UtilsCommon.h"
#include "UtilsImg.h"


QImage UtilsImg::takeScreenshot(const QRect &rect)
{
    QScreen *screen = QGuiApplication::primaryScreen();

    if (!screen)
    {
        return QImage();
    }

    // use width() - 1 and height() - 1 to remove black line on previewbox
    QPixmap capturePixmap = screen->grabWindow(0, rect.x(), rect.y(), rect.width() - 1, rect.height() - 1);

    return capturePixmap.toImage();
}

QString UtilsImg::getDebugScreenshotPath(QString filename, bool useTimestamp, QDateTime timestamp)
{
    if(useTimestamp)
    {
        QString timestampStr = UtilsCommon::timestampToStr(timestamp);
        filename = filename.replace(".png", "");
        return UtilsCommon::getAppDir(true) + filename + "_" + timestampStr + ".png";
    }
    else
    {
        return UtilsCommon::getAppDir(true) + filename;
    }
}
