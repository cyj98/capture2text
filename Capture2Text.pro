QT += core

!console {
    QT += gui network texttospeech
    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
}

include(vendor/vendor.pri)

TARGET = Capture2Text

console {
    TARGET = Capture2Text_CLI
}

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

console {
    DEFINES += CLI_BUILD
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp\
#    Application.cpp \
    Furigana.cpp \
    BoundingTextRect.cpp \
    QHotkeyHook.cpp \
#    RunGuard.cpp \
    CommandLine.cpp \
    UtilsLang.cpp \
    UtilsImg.cpp \
    PostProcess.cpp \
    PreProcess.cpp \
    OcrEngine.cpp \
    UtilsCommon.cpp


HEADERS  += \
#    Application.h \
    Furigana.h \
    BoundingTextRect.h \
    CommandLine.h \
    QHotkeyHook.h \
    UtilsLang.h \
    UtilsImg.h \
    PostProcess.h \
    PreProcess.h \
    PreProcessCommon.h \
    OcrEngine.h \
    UtilsCommon.h

!console {
    macx {
        OBJECTIVE_SOURCES += MacMouseMonitor.mm
        OBJECTIVE_HEADERS += MacMouseMonitor.h
        LIBS += -framework AppKit
    }

    SOURCES += \
        MainWindow.cpp \
        SettingsDialog.cpp \
        Settings.cpp \
        PopupDialog.cpp \
        Preview.cpp \
        SampleBox.cpp \
        Translate.cpp \
#        Hotkey.cpp \
        HotkeyWidget.cpp \
        CaptureBox.cpp \
        AboutDialog.cpp \
        WelcomeDialog.cpp \
#        KeyboardHook.cpp \
        MouseHook.cpp \
        Speech.cpp  \

    HEADERS  += \
        MainWindow.h \
#        RunGuard.h \
        SettingsDialog.h \
        Preview.h \
        Settings.h \
        PopupDialog.h \
        SampleBox.h \
        Translate.h \
#        Hotkey.h \
        HotkeyWidget.h \
        CaptureBox.h \
        AboutDialog.h \
        ReplyTimeout.h \
        WelcomeDialog.h \
#        KeyboardHook.h \
        MouseHook.h \
        Speech.h \

    FORMS    += \
        SettingsDialog.ui \
        PopupDialog.ui \
        AboutDialog.ui \
        HotkeyWidget.ui \
        WelcomeDialog.ui
}

## Disable warning: C4305: 'initializing': truncation from 'double' to 'l_float32'
#QMAKE_CXXFLAGS += /wd4305

## Disable warning: C4099: 'ETEXT_DESC': type name first seen using 'class' now seen using 'struct'
#QMAKE_CXXFLAGS += /wd4099

#INCLUDEPATH += E:\Dev\cpp\Tess4\tesseract\api
#INCLUDEPATH += E:\Dev\cpp\Tess4\tesseract\ccmain
#INCLUDEPATH += E:\Dev\cpp\Tess4\tesseract\ccstruct
#INCLUDEPATH += E:\Dev\cpp\Tess4\tesseract\ccutil
#INCLUDEPATH += E:\Dev\cpp\Leptonica_1.74.4\src

## Tesseract and Leptonica
#bits32 {
#    # 32-bit
#    win32:CONFIG(release, debug|release): LIBS += -LE:\Dev\cpp\Leptonica_1.74.4\bin\32\Release \
#        -LE:\Dev\cpp\Tess4\tesseract\build\Release \
#        -ltesseract400
#    else:win32:CONFIG(debug, debug|release): LIBS += -LE:\Dev\cpp\Leptonica_1.74.4\bin\32\Debug \
#        -LE:\Dev\cpp\Tess4\tesseract\build\Debug \
#        -ltesseract400d

#} else {
#    # 64-bit
#    win32:CONFIG(release, debug|release): LIBS += -LE:\Dev\cpp\Leptonica_1.74.4\bin\64\Release \
#        -LE:\Dev\cpp\Tess4\tesseract\win64\Release \
#        -ltesseract400
#    else:win32:CONFIG(debug, debug|release): LIBS += -LE:\Dev\cpp\Leptonica_1.74.4\bin\64\Debug \
#        -LE:\Dev\cpp\Tess4\tesseract\win64\Debug \
#        -ltesseract400d
#}


#LIBS += -lpvt.cppan.demo.danbloomberg.leptonica-1.74.4
#LIBS += -luser32

macx: {
    PKG_CONFIG = /usr/local/bin/pkg-config
}

CONFIG += link_pkgconfig
PKGCONFIG += tesseract opencv4 lept

!console {
    RESOURCES += \
        resource.qrc
}

# Needed for the icon
RC_FILE = Capture2Text.rc

