#include <gtest/gtest.h>
#include "square.hpp"

class SquareTest : public ::testing::Test {
protected:
    Point<int> testCenter{1, 2};
    Square<int> validSquare{testCenter, 5};
};

TEST_F(SquareTest, ValidConstruction) {
    EXPECT_NO_THROW({
                        Square<int> square(testCenter, 5);
                    });

    Point<int> center = validSquare.getCenter();
    EXPECT_EQ(center.getX(), testCenter.getX());
    EXPECT_EQ(center.getY(), testCenter.getY());
}

TEST_F(SquareTest, Area) {
    EXPECT_DOUBLE_EQ(validSquare.area(), 25.0);

    Square<int> unitSquare(testCenter, 1);
    EXPECT_DOUBLE_EQ(unitSquare.area(), 1.0);

    Square<int> largeSquare(testCenter, 10);
    EXPECT_DOUBLE_EQ(largeSquare.area(), 100.0);
}

TEST_F(SquareTest, Clone) {
    auto cloned = validSquare.clone();

    EXPECT_NE(&validSquare, cloned.get());

    EXPECT_DOUBLE_EQ(cloned->area(), validSquare.area());

    Point<int> clonedCenter = cloned->getCenter();
    EXPECT_EQ(clonedCenter.getX(), testCenter.getX());
    EXPECT_EQ(clonedCenter.getY(), testCenter.getY());
}

