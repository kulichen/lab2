#include <gtest/gtest.h>

extern "C" {
#include "_text.h"
}

// позитивный тест
TEST (save, savetest1)
{
        /* Создаем структуру описания текста */
        text txt = create_text();
        append_line(txt, "qwe1\n");
        append_line(txt, "qwe2");

        int res = save(txt, (char*)"savetest1.txt");

        EXPECT_EQ(1, res);

        text loadtxt = create_text();
        load(loadtxt, (char*)"savetest1.txt");

        EXPECT_EQ(txt->length,loadtxt->length);
}

// негативный тест
TEST (save, savetest2)
{
        /* Создаем структуру описания текста */
        text txt = create_text();

        int res = save(txt, (char*)"savetest2.txt");

        EXPECT_EQ(0, res);
}

