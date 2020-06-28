#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}

TEST(m, mtest1)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    auto res = m(txt, 0, 0);

    EXPECT_EQ(0, res);
    EXPECT_EQ(1, txt->cursor->position);
}

TEST(m, mtest2)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    auto res = m(txt, -1, 0);

    EXPECT_EQ(-1, res);
    EXPECT_EQ(1, txt->cursor->position);
}

TEST(m, mtest3)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    auto res = m(txt, 4, 0);

    EXPECT_EQ(3, res);
    EXPECT_EQ(4, txt->cursor->position);
}

TEST(m, mtest4)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    auto res = m(txt, 0, 10);

    EXPECT_EQ(2, res);
    EXPECT_EQ(5, txt->cursor->position);
}

TEST(m, mtest5)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    auto res = m(txt, 0, -1);

    EXPECT_EQ(1, res);
    EXPECT_EQ(1, txt->cursor->position);
}
