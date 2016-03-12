#include <stdio.h>

#include "sample1.h"

#include "gtest/gtest.h"

TEST(TestCaseName, TestName) {
    EXPECT_EQ(true, IsPrime(7));
}

GTEST_API_ int main(int argc, char **argv) {
    printf("Running unit tests\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
