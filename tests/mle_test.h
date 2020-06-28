#include <gtest/gtest.h>
#include <string.h>

extern "C" {
#include "_text.h"
}

TEST(mle, mletest1)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    m(txt, 0, 0);
    auto res = mle(txt);

    EXPECT_EQ(1, res);

    EXPECT_EQ(5, txt->cursor->position);
}

TEST(mle, mletest2)
{
    /* Создаем структуру описания текста */
    text txt = create_text();
    append_line(txt, "qwe1\n");
    append_line(txt, "qwe2");

    m(txt, 0, 5);
    auto res = mle(txt);

    EXPECT_EQ(1, res);

    EXPECT_EQ(5, txt->cursor->position);
}
