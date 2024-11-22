#include <gtest/gtest.h>
#include "rectangle.hpp"

class RectangleTest : public ::testing::Test {
protected:
    Point<int> testCenter{1, 2};
    Rectangle<int> validRect{testCenter, 4, 3};
};

TEST_F(RectangleTest, ValidConstruction) {
    EXPECT_NO_THROW({
                        Rectangle<int> rect(testCenter, 4, 3);
                    });

    Point<int> center = validRect.getCenter();
    EXPECT_EQ(center.getX(), testCenter.getX());
    EXPECT_EQ(center.getY(), testCenter.getY());
}

TEST_F(RectangleTest, InvalidConstruction) {
    EXPECT_THROW({
                     Rectangle<int> rect(testCenter, -4, 3);
                 }, std::invalid_argument);

    EXPECT_THROW({
                     Rectangle<int> rect(testCenter, 4, -3);
                 }, std::invalid_argument);

    EXPECT_THROW({
                     Rectangle<int> rect(testCenter, 0, 3);
                 }, std::invalid_argument);

    EXPECT_THROW({
                     Rectangle<int> rect(testCenter, 4, 0);
                 }, std::invalid_argument);

    EXPECT_THROW({
                     Rectangle<int> rect(testCenter, -4, -3);
                 }, std::invalid_argument);
}

TEST_F(RectangleTest, Area) {
    EXPECT_DOUBLE_EQ(validRect.area(), 12.0);

    Rectangle<int> square(testCenter, 5, 5);
    EXPECT_DOUBLE_EQ(square.area(), 25.0);

    Rectangle<int> minimal(testCenter, 1, 1);
    EXPECT_DOUBLE_EQ(minimal.area(), 1.0);
}

