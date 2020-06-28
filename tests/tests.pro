include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS +=     \
    ../app/_text.h \
    ../app/text.h \
    r1ne_test.h \
    m_test.h \
    mle_test.h \
    save_test.h \
    showupfirst_test.h

SOURCES +=     main.cpp \
    ../app/save.c \
    ../app/load.c \
    ../app/remove_all.c \
    ../app/create_text.c \
    ../app/m.c \
    ../app/mle.c \
    ../app/showupfirst.c \
    ../app/r1ne.c \
    ../app/process_forward.c \
    ../app/append_line.c

INCLUDEPATH += ../app

DISTFILES +=
