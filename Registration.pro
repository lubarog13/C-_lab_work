QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudent.cpp \
    adduser.cpp \
    changestudent.cpp \
    changeuser.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_new.cpp \
    mainwindow_password.cpp \
    user.cpp \
    viewstudents.cpp \
    viewusers.cpp

HEADERS += \
    addstudent.h \
    adduser.h \
    changestudent.h \
    changeuser.h \
    mainwindow.h \
    mainwindow_new.h \
    mainwindow_password.h \
    user.h \
    viewstudents.h \
    viewusers.h

FORMS += \
    addstudent.ui \
    adduser.ui \
    changestudent.ui \
    changeuser.ui \
    mainwindow.ui \
    mainwindow_new.ui \
    mainwindow_password.ui \
    viewstudents.ui \
    viewusers.ui

TRANSLATIONS += \
    Registration_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES += \
    images/confusuon.png \
    images/email.png \
    images/name.png \
    images/password.png \
    images/question.png \
    images/reg.png \
    images/registration.png \
    images/remove-button.png \
    images/welcome.png
