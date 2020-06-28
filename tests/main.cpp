#include "r1ne_test.h"
#include "mle_test.h"
#include "showupfirst_test.h"
#include "m_test.h"
#include "save_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
