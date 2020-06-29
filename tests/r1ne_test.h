#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}

TEST (r1ne, r1netest1)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(2, res);

    EXPECT_EQ(txt->length + 1, startl);
}

TEST (r1ne, r1netest2)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(0, res);

    EXPECT_EQ(txt->length + 1, startl);
}

TEST (r1ne, r1netest3)
{
    /* Создаем структуру описания текста */
    text txt = create_text();

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(-1, res);

    EXPECT_EQ(txt->length, startl);
}

TEST (r1ne, r1netest4)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "\n");
    append_line(txt, "\n");

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(-2, res);

    EXPECT_EQ(txt->length, startl);
}

TEST (r1ne, r1netest5)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "\n");
    append_line(txt, "qwe2\n");
    append_line(txt, "qwe3");

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(1, res);

    EXPECT_EQ(txt->length + 1, startl);
}

TEST (r1ne, r1netest6)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "\n");
    append_line(txt, "qwe2\n");

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(3, res);

    EXPECT_EQ(txt->length + 1, startl);
}
TEST (r1ne, r1netest7)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "\n");
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2\n");
    
    m(txt, 1, 0);

    unsigned long long startl = txt->length;

    int res = r1ne(txt);

    EXPECT_EQ(3, res);

    EXPECT_EQ(txt->length + 1, startl);
}
