#include <gtest/gtest.h>
#include <string.h>
#include <errno.h>

extern "C" {
#include "_text.h"
}

TEST(suf, suftest1)
{
    text txt = create_text();

    append_line(txt, "line1\n");
    append_line(txt, "line1 word1\n");

    testing::internal::CaptureStdout();

    showupfirst(txt);
    std::string text = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(text.c_str(), "Line1\nLine1 Word1|\n");

    free(txt);
}
