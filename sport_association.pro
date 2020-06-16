QT       += core gui sql network
QT       += printsupport
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnements.cpp \
    abonnes.cpp \
    billet.cpp \
    categorie.cpp \
    categories.cpp \
    connection.cpp \
    dialog.cpp \
    discipline.cpp \
    joueur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    match.cpp \
    produits.cpp \
    smtp.cpp \
    staff.cpp \
    stat_anis.cpp \
    stat_chedli.cpp \
    stat_yas.cpp \
    statistique.cpp \
    stats.cpp

HEADERS += \
    abonnements.h \
    abonnes.h \
    billet.h \
    categorie.h \
    categories.h \
    connection.h \
    dialog.h \
    discipline.h \
    joueur.h \
    login.h \
    mainwindow.h \
    match.h \
    produits.h \
    smtp.h \
    staff.h \
    stat_anis.h \
    stat_chedli.h \
    stat_yas.h \
    statistique.h \
    stats.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
