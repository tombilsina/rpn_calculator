#include <gtest/gtest.h>
#include "rpn.h"
#include <stdexcept>
#include <cmath>

TEST(RPNTest, BasicAddition) {
    EXPECT_DOUBLE_EQ(evaluate_rpn("2 3 +"), 5.0);
}
TEST(RPNTest, BasicOperations) {
EXPECT_DOUBLE_EQ(evaluate_rpn("2 3 +"), 5.0);
EXPECT_DOUBLE_EQ(evaluate_rpn("10 5 -"), 5.0);
EXPECT_DOUBLE_EQ(evaluate_rpn("4 3 *"), 12.0);
EXPECT_DOUBLE_EQ(evaluate_rpn("20 4 /"), 5.0);
}
TEST(RPNTest, InvalidInput) {
EXPECT_THROW(evaluate_rpn("2 +"), std::invalid_argument);
EXPECT_THROW(evaluate_rpn("1 0 /"), std::invalid_argument);
EXPECT_THROW(evaluate_rpn("a b +"), std::invalid_argument);
}
TEST(RPNTest, SqrtFunction) {
EXPECT_DOUBLE_EQ(evaluate_rpn("9 sqrt"), 3.0);
EXPECT_DOUBLE_EQ(evaluate_rpn("2 sqrt"), std::sqrt(2));
}
TEST(RPNTest, SqrtInvalidInput) {
EXPECT_THROW(evaluate_rpn("sqrt"), std::invalid_argument); // Не хватает операндов
EXPECT_THROW(evaluate_rpn("-1 sqrt"), std::invalid_argument); // Отрицательное число
}
