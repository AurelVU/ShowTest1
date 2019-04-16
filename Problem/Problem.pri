!PROBLEM {
CONFIG += PROBLEM
INCLUDEPATH += $$PWD/../
include($$PWD/../Eigen/Eigen.pri)

HEADERS += \
    $$PWD/getterproblem.h \
    $$PWD/getterproblemfile.h

SOURCES += \
    $$PWD/getterproblem.cpp \
    $$PWD/getterproblemfile.cpp 

}

HEADERS += \
    $$PWD/problem.h

SOURCES += \
    $$PWD/problem.cpp
 
