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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QColor>
#include <QCoreApplication>
#include <QFont>
#include <QSettings>
#include <QSize>
#include <QTextToSpeech>

//#include "Hotkey.h"
#include "PostProcess.h"

class Settings
{
public:
    static const QColor defaultCaptureBoxBackgroundColor;
    static QColor getCaptureBoxBackgroundColor() { return settings->value("CaptureBox/BackgroundColor", defaultCaptureBoxBackgroundColor).value<QColor>(); }
    static void setCaptureBoxBackgroundColor( QColor value) { settings->setValue("CaptureBox/BackgroundColor", value); }

    static const QColor defaultCaptureBoxBorderColor;
    static QColor getCaptureBoxBorderColor() { return settings->value("CaptureBox/BorderColor", defaultCaptureBoxBorderColor).value<QColor>(); }
    static void setCaptureBoxBorderColor( QColor value) { settings->setValue("CaptureBox/BorderColor", value); }

    static const bool defaultDebugPrependCoords = false;
    static bool getDebugPrependCoords() { return settings->value("Debug/PrependCoords", defaultDebugPrependCoords).toBool(); }
    static void setDebugPrependCoords(bool value) { settings->setValue("Debug/PrependCoords", value); }

//    static const bool defaultDebugSaveCaptureImage = false;
    static const bool defaultDebugSaveCaptureImage = true;
    static bool getDebugSaveCaptureImage() { return settings->value("Debug/SaveCaptureImage", defaultDebugSaveCaptureImage).toBool(); }
    static void setDebugSaveCaptureImage(bool value) { settings->setValue("Debug/SaveCaptureImage", value); }

//    static const bool defaultDebugSaveEnhancedImage = false;
    static const bool defaultDebugSaveEnhancedImage = true;
    static bool getDebugSaveEnhancedImage() { return settings->value("Debug/SaveEnhancedImage", defaultDebugSaveEnhancedImage).toBool(); }
    static void setDebugSaveEnhancedImage(bool value) { settings->setValue("Debug/SaveEnhancedImage", value); }

    static const bool defaultDebugAppendTimestampToImage = false;
    static bool getDebugAppendTimestampToImage() { return settings->value("Debug/AppendTimestampToImage", defaultDebugAppendTimestampToImage).toBool(); }
    static void setDebugAppendTimestampToImage(bool value) { settings->setValue("Debug/AppendTimestampToImage", value); }

    static const QString defaultHotkeyCaptureBox;
    static QString getHotkeyCaptureBox() { return settings->value("Hotkey/CaptureBox", defaultHotkeyCaptureBox).toString(); }
    static void setHotkeyCaptureBox(QString value) { settings->setValue("Hotkey/CaptureBox", value); }

    static const QString defaultHotkeyReCaptureLast;
    static QString getHotkeyReCaptureLast() { return settings->value("Hotkey/ReCaptureLast", defaultHotkeyReCaptureLast).toString(); }
    static void setHotkeyReCaptureLast(QString value) { settings->setValue("Hotkey/ReCaptureLast", value); }

    static const QString defaultHotkeyTextLineCapture;
    static QString getHotkeyTextLineCapture() { return settings->value("Hotkey/TextLineCapture", defaultHotkeyTextLineCapture).toString(); }
    static void setHotkeyTextLineCapture(QString value) { settings->setValue("Hotkey/TextLineCapture", value); }

    static const QString defaultHotkeyForwardTextLineCapture;
    static QString getHotkeyForwardTextLineCapture() { return settings->value("Hotkey/ForwardTextLineCapture", defaultHotkeyForwardTextLineCapture).toString(); }
    static void setHotkeyForwardTextLineCapture(QString value) { settings->setValue("Hotkey/ForwardTextLineCapture", value); }

    static const QString defaultHotkeyBubbleCapture;
    static QString getHotkeyBubbleCapture() { return settings->value("Hotkey/BubbleCapture", defaultHotkeyBubbleCapture).toString(); }
    static void setHotkeyBubbleCapture(QString value) { settings->setValue("Hotkey/BubbleCapture", value); }

    static const QString defaultHotkeyLang1;
    static QString getHotkeyLang1() { return settings->value("Hotkey/Lang1", defaultHotkeyLang1).toString(); }
    static void setHotkeyLang1(QString value) { settings->setValue("Hotkey/Lang1", value); }

    static const QString defaultHotkeyLang2;
    static QString getHotkeyLang2() { return settings->value("Hotkey/Lang2", defaultHotkeyLang2).toString(); }
    static void setHotkeyLang2(QString value) { settings->setValue("Hotkey/Lang2", value); }

    static const QString defaultHotkeyLang3;
    static QString getHotkeyLang3() { return settings->value("Hotkey/Lang3", defaultHotkeyLang3).toString(); }
    static void setHotkeyLang3(QString value) { settings->setValue("Hotkey/Lang3", value); }

    static const QString defaultHotkeyTextOrientation;
    static QString getHotkeyTextOrientation() { return settings->value("Hotkey/TextOrientation", defaultHotkeyTextOrientation).toString(); }
    static void setHotkeyTextOrientation(QString value) { settings->setValue("Hotkey/TextOrientation", value); }

    static const QString defaultHotkeyWhitelist;
    static QString getHotkeyWhitelist() { return settings->value("Hotkey/Whitelist", defaultHotkeyWhitelist).toString(); }
    static void setHotkeyWhitelist(QString value) { settings->setValue("Hotkey/Whitelist", value); }

    static const QString defaultHotkeyBlacklist;
    static QString getHotkeyBlacklist() { return settings->value("Hotkey/Blacklist", defaultHotkeyBlacklist).toString(); }
    static void setHotkeyBlacklist(QString value) { settings->setValue("Hotkey/Blacklist", value); }

    static const QString defaultOcrLang;
    static QString getOcrLang() { return settings->value("OCR/Language", defaultOcrLang).toString(); }
    static void setOcrLang(QString value) { settings->setValue("OCR/Language", value); }

    static const QString defaultOcrQuickAccessLang1;
    static QString getOcrQuickAccessLang1() { return settings->value("OCR/QuickAccessLang1", defaultOcrQuickAccessLang1).toString(); }
    static void setOcrQuickAccessLang1(QString value) { settings->setValue("OCR/QuickAccessLang1", value); }

    static const QString defaultOcrQuickAccessLang2;
    static QString getOcrQuickAccessLang2() { return settings->value("OCR/QuickAccessLang2", defaultOcrQuickAccessLang2).toString(); }
    static void setOcrQuickAccessLang2(QString value) { settings->setValue("OCR/QuickAccessLang2", value); }

    static const QString defaultOcrQuickAccessLang3;
    static QString getOcrQuickAccessLang3() { return settings->value("OCR/QuickAccessLang3", defaultOcrQuickAccessLang3).toString(); }
    static void setOcrQuickAccessLang3(QString value) { settings->setValue("OCR/QuickAccessLang3", value); }

    static const bool defaultOcrEnableWhitelist = false;
    static bool getOcrEnableWhitelist() { return settings->value("OCR/EnableWhitelist", defaultOcrEnableWhitelist).toBool(); }
    static void setOcrEnableWhitelist(bool value) { settings->setValue("OCR/EnableWhitelist", value); }

    static const QString defaultOcrWhitelist;
    static QString getOcrWhitelist() { return settings->value("OCR/Whitelist", defaultOcrWhitelist).toString(); }
    static void setOcrWhitelist(QString value) { settings->setValue("OCR/Whitelist", value); }

    static const bool defaultOcrEnableBlacklist = false;
    static bool getOcrEnableBlacklist() { return settings->value("OCR/EnableBlacklist", defaultOcrEnableBlacklist).toBool(); }
    static void setOcrEnableBlacklist(bool value) { settings->setValue("OCR/EnableBlacklist", value); }

    static const QString defaultOcrBlacklist;
    static QString getOcrBlacklist() { return settings->value("OCR/Blacklist", defaultOcrBlacklist).toString(); }
    static void setOcrBlacklist(QString value) { settings->setValue("OCR/Blacklist", value); }

    static const QString defaultOcrTextOrientation;
    static QString getOcrTextOrientation() { return settings->value("OCR/TextOrientation", defaultOcrTextOrientation).toString(); }
    static void setOcrTextOrientation(QString value) { settings->setValue("OCR/TextOrientation", value); }

    static const QString defaultOcrTesseractConfigFile;
    static QString getOcrTesseractConfigFile() { return settings->value("OCR/TesseractConfigFile", defaultOcrTesseractConfigFile).toString(); }
    static void setOcrTesseractConfigFile(QString value) { settings->setValue("OCR/TesseractConfigFile", value); }

    static const double defaultOcrScaleFactor;
    static double getOcrScaleFactor() { return settings->value("OCR/ScaleFactor", defaultOcrScaleFactor).toDouble(); }
    static void setOcrScaleFactor(double value) { settings->setValue("OCR/ScaleFactor", value); }

//    static const bool defaultOcrTrim = false;
    static const bool defaultOcrTrim = true;
    static bool getOcrTrim() { return settings->value("OCR/Trim", defaultOcrTrim).toBool(); }
    static void setOcrTrim(bool value) { settings->setValue("OCR/Trim", value); }

//    static const bool defaultOcrDeskew = false;
    static const bool defaultOcrDeskew = true;
    static bool getOcrDeskew() { return settings->value("OCR/Deskew", defaultOcrDeskew).toBool(); }
    static void setOcrDeskew(bool value) { settings->setValue("OCR/Deskew", value); }

    static const int defaultTextLineCaptureLength = 1500;
    static int getTextLineCaptureLength() { return settings->value("TextLineCapture/Length", defaultTextLineCaptureLength).toInt(); }
    static void setTextLineCaptureLength(int value) { settings->setValue("TextLineCapture/Length", value); }

    static const int defaultTextLineCaptureWidth = 70;
    static int getTextLineCaptureWidth() { return settings->value("TextLineCapture/Width", defaultTextLineCaptureWidth).toInt(); }
    static void setTextLineCaptureWidth(int value) { settings->setValue("TextLineCapture/Width", value); }

    static const int defaultTextLineCaptureLookahead = 14;
    static int getTextLineCaptureLookahead() { return settings->value("TextLineCapture/Lookahead", defaultTextLineCaptureLookahead).toInt(); }
    static void setTextLineCaptureLookahead(int value) { settings->setValue("TextLineCapture/Lookahead", value); }

    static const int defaultTextLineCaptureLookbehind = 14;
    static int getTextLineCaptureLookbehind() { return settings->value("TextLineCapture/Lookbehind", defaultTextLineCaptureLookbehind).toInt(); }
    static void setTextLineCaptureLookbehind(int value) { settings->setValue("TextLineCapture/Lookbehind", value); }

    static const int defaultTextLineCaptureSearchRadius = 30;
    static int getTextLineCaptureSearchRadius() { return settings->value("TextLineCapture/SearchRadius", defaultTextLineCaptureSearchRadius).toInt(); }
    static void setTextLineCaptureSearchRadius(int value) { settings->setValue("TextLineCapture/SearchRadius", value); }

    static const int defaultForwardTextLineCaptureLength = 750;
    static int getForwardTextLineCaptureLength() { return settings->value("ForwardTextLineCapture/Length", defaultForwardTextLineCaptureLength).toInt(); }
    static void setForwardTextLineCaptureLength(int value) { settings->setValue("ForwardTextLineCapture/Length", value); }

    static const int defaultForwardTextLineCaptureWidth = 70;
    static int getForwardTextLineCaptureWidth() { return settings->value("ForwardTextLineCapture/Width", defaultForwardTextLineCaptureWidth).toInt(); }
    static void setForwardTextLineCaptureWidth(int value) { settings->setValue("ForwardTextLineCapture/Width", value); }

    static const int defaultForwardTextLineCaptureLookahead = 14;
    static int getForwardTextLineCaptureLookahead() { return settings->value("ForwardTextLineCapture/Lookahead", defaultForwardTextLineCaptureLookahead).toInt(); }
    static void setForwardTextLineCaptureLookahead(int value) { settings->setValue("ForwardTextLineCapture/Lookahead", value); }

    static const int defaultForwardTextLineCaptureLookbehind = 1;
    static int getForwardTextLineCaptureLookbehind() { return settings->value("ForwardTextLineCapture/Lookbehind", defaultForwardTextLineCaptureLookbehind).toInt(); }
    static void setForwardTextLineCaptureLookbehind(int value) { settings->setValue("ForwardTextLineCapture/Lookbehind", value); }

    static const int defaultForwardTextLineCaptureStartOffset = 25;
    static int getForwardTextLineCaptureStartOffset() { return settings->value("ForwardTextLineCapture/StartOffset", defaultForwardTextLineCaptureStartOffset).toInt(); }
    static void setForwardTextLineCaptureStartOffset(int value) { settings->setValue("ForwardTextLineCapture/StartOffset", value); }

    static const int defaultForwardTextLineCaptureSearchRadius = 30;
    static int getForwardTextLineCaptureSearchRadius() { return settings->value("ForwardTextLineCapture/SearchRadius", defaultForwardTextLineCaptureSearchRadius).toInt(); }
    static void setForwardTextLineCaptureSearchRadius(int value) { settings->setValue("ForwardTextLineCapture/SearchRadius", value); }

    static const bool defaultForwardTextLineCaptureFirstWord = false;
    static bool getForwardTextLineCaptureFirstWord() { return settings->value("ForwardTextLineCapture/FirstWord", defaultForwardTextLineCaptureFirstWord).toBool(); }
    static void setForwardTextLineCaptureFirstWord(bool value) { settings->setValue("ForwardTextLineCapture/FirstWord", value); }

//    static const int defaultBubbleCaptureWidth = 500;
    static const int defaultBubbleCaptureWidth = 250;
    static int getBubbleCaptureWidth() { return settings->value("BubbleCapture/Width", defaultBubbleCaptureWidth).toInt(); }
    static void setBubbleCaptureWidth(int value) { settings->setValue("BubbleCapture/Width", value); }

//    static const int defaultBubbleCaptureHeight = 500;
    static const int defaultBubbleCaptureHeight = 250;
    static int getBubbleCaptureHeight() { return settings->value("BubbleCapture/Height", defaultBubbleCaptureHeight).toInt(); }
    static void setBubbleCaptureHeight(int value) { settings->setValue("BubbleCapture/Height", value); }

    static const bool defaultOutputKeepLineBreaks = true;
    static bool getOutputKeepLineBreaks() { return settings->value("Output/KeepLineBreaks", defaultOutputKeepLineBreaks).toBool(); }
    static void setOutputKeepLineBreaks(bool value) { settings->setValue("Output/KeepLineBreaks", value); }

    static const bool defaultOutputClipboard = true;
    static bool getOutputClipboard() { return settings->value("Output/OutputClipboard", defaultOutputClipboard).toBool(); }
    static void setOutputClipboard(bool value) { settings->setValue("Output/OutputClipboard", value); }

    static const QString defaultOutputLogFile;
    static QString getOutputLogFile() { return settings->value("Output/LogFile", defaultOutputLogFile).toString(); }
    static void setOutputLogFile(QString value) { settings->setValue("Output/LogFile", value); }

    static const bool defaultOutputLogFileEnable = false;
    static bool getOutputLogFileEnable() { return settings->value("Output/LogFileEnable", defaultOutputLogFileEnable).toBool(); }
    static void setOutputLogFileEnable(bool value) { settings->setValue("Output/LogFileEnable", value); }

    static const QString defaultOutputLogFormat;
    static QString getOutputLogFormat() { return settings->value("Output/LogFormat", defaultOutputLogFormat).toString(); }
    static void setOutputLogFormat(QString value) { settings->setValue("Output/LogFormat", value); }

    static QSize getOutputPopupWindowSize() { return settings->value("Output/OutputPopupWindowSize", QSize(355, 165)).toSize(); }
    static void setOutputPopupWindowSize(QSize value) { settings->setValue("Output/OutputPopupWindowSize", value); }

    static const QFont defaultOutputPopupFont;
    static QFont getOutputPopupFont() { return settings->value("Output/OutputPopupFont", defaultOutputPopupFont).value<QFont>(); }
    static void setOutputPopupFont( QFont value) { settings->setValue("Output/OutputPopupFont", value); }

    static const bool defaultOutputShowPopup = true;
    static bool getOutputShowPopup() { return settings->value("Output/OutputPopup", defaultOutputShowPopup).toBool(); }
    static void setOutputShowPopup(bool value) { settings->setValue("Output/OutputPopup", value); }

    static const bool defaultOutputCallExeEnable = false;
    static bool getOutputCallExeEnable() { return settings->value("Output/CallExeEnable", defaultOutputCallExeEnable).toBool(); }
    static void setOutputCallExeEnable(bool value) { settings->setValue("Output/CallExeEnable", value); }

    static const QString defaultOutputCallExe;
    static QString getOutputCallExe() { return settings->value("Output/CallExe", defaultOutputCallExe).toString(); }
    static void setOutputCallExe(QString value) { settings->setValue("Output/CallExe", value); }

    static bool getOutputPopupTopmost() { return settings->value("Output/PopupTopmost", true).toBool(); }
    static void setOutputPopupTopmost(bool value) { settings->setValue("Output/PopupTopmost", value); }

    static const QColor defaultPreviewBackgroundColor;
    static QColor getPreviewBackgroundColor() { return settings->value("Preview/BackgroundColor", defaultPreviewBackgroundColor).value<QColor>(); }
    static void setPreviewBackgroundColor( QColor value) { settings->setValue("Preview/BackgroundColor", value); }

    static const QColor defaultPreviewBorderColor;
    static QColor getPreviewBorderColor() { return settings->value("Preview/BorderColor", defaultPreviewBorderColor).value<QColor>(); }
    static void setPreviewBorderColor( QColor value) { settings->setValue("Preview/BorderColor", value); }

    static const bool defaultPreviewEnabled = true;
    static bool getPreviewEnabled() { return settings->value("Preview/Enabled", defaultPreviewEnabled).toBool(); }
    static void setPreviewEnabled(bool value) { settings->setValue("Preview/Enabled", value); }

    static const QString defaultPreviewPosition;
    static QString getPreviewPosition() { return settings->value("Preview/Position", defaultPreviewPosition).toString(); }
    static void setPreviewPosition(QString value) { settings->setValue("Preview/Position", value); }

    static const QColor defaultPreviewTextColor;
    static QColor getPreviewTextColor() { return settings->value("Preview/TextColor", defaultPreviewTextColor).value<QColor>(); }
    static void setPreviewTextColor( QColor value) { settings->setValue("Preview/TextColor", value); }

    static const QFont defaultPreviewTextFont;
    static QFont getPreviewTextFont() { return settings->value("Preview/TextFont", defaultPreviewTextFont).value<QFont>(); }
    static void setPreviewTextFont( QFont value) { settings->setValue("Preview/TextFont", value); }

    static QList<Replacement> getOcrReplacementList(QString lang);
    static void setOcrReplacementList(QString lang, QList<Replacement> value);

    static const bool defaultTranslateAddToClipboard = false;
    static bool getTranslateAddToClipboard() { return settings->value("Translate/AddToClipboard", defaultTranslateAddToClipboard).toBool(); }
    static void setTranslateAddToClipboard(bool value) { settings->setValue("Translate/AddToClipboard", value); }

    static const bool defaultTranslateAddToPopup = false;
    static bool getTranslateAddToPopup() { return settings->value("Translate/AddToPopup", defaultTranslateAddToPopup).toBool(); }
    static void setTranslateAddToPopup(bool value) { settings->setValue("Translate/AddToPopup", value); }

    static QString getTranslateSeparator() { return settings->value("Translate/Separator", "Space").toString(); }
    static void setTranslateSeparator(QString value) { settings->setValue("Translate/Separator", value); }
    static QString separatorToStr(QString separator);

    static QString getTranslateLang(QString ocrLang);
    static void setTranslateLang(QString ocrLang, QString translateLang);

    static const int defaultTranslateServerTimeout = 2000;
    static int getTranslateServerTimeout() { return settings->value("Translate/ServerTimeout", defaultTranslateServerTimeout).toInt(); }
    static void setTranslateServerTimeout(int value) { settings->setValue("Translate/ServerTimeout", value); }

    static const bool defaultSpeechEnable = false;
    static bool getSpeechEnable() { return settings->value("Speech/Enable", defaultSpeechEnable).toBool(); }
    static void setSpeechEnable(bool value) { settings->setValue("Speech/Enable", value); }

    static const int defaultSpeechVolume = 70;
    static int getSpeechVolume() { return settings->value("Speech/Volume", defaultSpeechVolume).toInt(); }
    static void setSpeechVolume(int value) { settings->setValue("Speech/Volume", value); }

    static const int defaultSpeechRate = 0;
    static const int defaultSpeechPitch = 0;
    static void getSpeechInfo(QString ocrLang, QString &locale, QString &voice, int &rate, int &pitch);
    static void setSpeechInfo(QString ocrLang, QString locale, QString voice, int rate, int pitch);

    static bool getMiscShowWelcome() { return settings->value("Misc/ShowWelcome", true).toBool(); }
    static void setMiscShowWelcome(bool value) { settings->setValue("Misc/ShowWelcome", value); }

    static QString getMiscVersion() { return settings->value("Misc/Version", QCoreApplication::applicationVersion()).toString(); }
    static void setMiscVersion(QString value) { settings->setValue("Misc/Version", value); }

private:

    Settings() { };
    static QSettings *settings;
};

#endif // SETTINGS_H
