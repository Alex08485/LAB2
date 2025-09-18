#include "gtest/gtest.h"
#include "rpn.h"
#include <stdexcept>
#include <cmath>

// --- Тесты для базовых операций ---
TEST(RPNTest, BasicAddition) {
    ASSERT_DOUBLE_EQ(evaluate_rpn("3 4 +"), 7.0);
}

TEST(RPNTest, ComplexExpression) {
    ASSERT_DOUBLE_EQ(evaluate_rpn("15 7 1 1 + - / 3 * 2 1 1 + + -"), 5.0);
}

// --- Тесты для обработки ошибок ---
TEST(RPNTest, DivisionByZero) {
    ASSERT_THROW(evaluate_rpn("1 0 /"), std::runtime_error);
}

TEST(RPNTest, InvalidExpression) {
    ASSERT_THROW(evaluate_rpn("2 +"), std::runtime_error);
}
