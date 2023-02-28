QT       += core gui

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
    add.cpp \
    change.cpp \
    insert.cpp \
    main.cpp \
    mainone.cpp \
    salary.cpp \
    search.cpp \
    searchsalary.cpp \
    summary.cpp \
    textbox.cpp \
    title.cpp \
    unit.cpp

HEADERS += \
    DoubleLinkList.h \
    add.h \
    change.h \
    date_t.h \
    employee.h \
    insert.h \
    job_t.h \
    mainone.h \
    salary.h \
    search.h \
    searchsalary.h \
    staff.h \
    summary.h \
    textbox.h \
    title.h \
    unit.h

FORMS += \
    add.ui\
    change.ui \
    insert.ui \
    mainone.ui \
    salary.ui \
    search.ui \
    searchsalary.ui \
    summary.ui \
    textbox.ui \
    title.ui \
    unit.ui

RC_ICONS = 2.ico


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_CXXFLAGS += -Wno-unused-parameter

QMAKE_CXXFLAGS += -Wno-unused-variable
