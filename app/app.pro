TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    create_text.c \
    load.c \
    remove_all.c \
    mle.c \
    m.c \
    r1ne.c \
    showupfirst.c \
    save.c \
    append_line.c \
    process_forward.c

HEADERS += text.h \
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
