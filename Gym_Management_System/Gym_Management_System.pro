QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/GymClass/classesbookingmanagement.cpp \
    Model/GymClass/classesmanagement.cpp \
    Model/GymClass/gymclass.cpp \
    Model/PadelCourt/padelcourt.cpp \
    Model/PadelCourt/padelcourtbookingmanagement.cpp \
    Model/PadelCourt/padelcourtmanagement.cpp \
    Model/Settings/systemanalytics.cpp \
    Model/Stuff/Member/member.cpp \
    Model/Stuff/Member/membersmanagement.cpp \
    Model/Stuff/coach.cpp \
    Model/Stuff/manager.cpp \
    Model/Stuff/person.cpp \
    Model/Stuff/receptionist.cpp \
    Model/Stuff/stuffmanagement.cpp \
    Model/Subscription/subscription.cpp \
    Model/Subscription/subscriptionmanager.cpp \
    Model/Workout&Exercises/exercise.cpp \
    Model/Workout&Exercises/workout.cpp \
    main.cpp

HEADERS += \
    Model/GymClass/classesbookingmanagement.h \
    Model/GymClass/classesmanagement.h \
    Model/GymClass/gymclass.h \
    Model/PadelCourt/padelcourt.h \
    Model/PadelCourt/padelcourtbookingmanagement.h \
    Model/PadelCourt/padelcourtmanagement.h \
    Model/Settings/systemanalytics.h \
    Model/Stuff/Date.h \
    Model/Stuff/Member/member.h \
    Model/Stuff/Member/membersmanagement.h \
    Model/Stuff/coach.h \
    Model/Stuff/enRole.h \
    Model/Stuff/manager.h \
    Model/Stuff/person.h \
    Model/Stuff/receptionist.h \
    Model/Stuff/stuffmanagement.h \
    Model/Subscription/enStatus.h \
    Model/Subscription/enSubscriptionPeriod.h \
    Model/Subscription/enSubscriptionType.h \
    Model/Subscription/subscription.h \
    Model/Subscription/subscriptionmanager.h \
    Model/Workout&Exercises/exercise.h \
    Model/Workout&Exercises/workout.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
