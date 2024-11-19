#include "math_operations.h"
#include <gtest/gtest.h>

TEST(MathOperationsTest, Add) {
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(-5, -3), -8);
}

TEST(MathOperationsTest, Multiply) {
    EXPECT_EQ(multiply(5, 3), 15);
    EXPECT_EQ(multiply(-1, 1), -1);
    EXPECT_EQ(multiply(0, 10), 0);
    EXPECT_EQ(multiply(-5, -3), 15);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}