#include <gtest/gtest.h>
#include "figureArray.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "figure.hpp"

class ArrayTest : public ::testing::Test {
protected:
    Point<int> testCenter{0, 0};
    std::shared_ptr<Figure<int>> rect = std::make_shared<Rectangle<int>>(testCenter, 4, 3);
    std::shared_ptr<Figure<int>> square = std::make_shared<Square<int>>(testCenter, 5);
    Array<std::shared_ptr<Figure<int>>> array;

    void SetUp() override {
        array.add(rect);
        array.add(square);
    }
};


TEST_F(ArrayTest, Constructor) {
    Array<std::shared_ptr<Figure<int>>> emptyArray;
    EXPECT_EQ(emptyArray.size(), 0);
}


TEST_F(ArrayTest, Removal) {
    EXPECT_EQ(array.size(), 2);

    array.remove(0);
    EXPECT_EQ(array.size(), 1);


    EXPECT_DOUBLE_EQ(array[0]->area(), 25.0);
}


TEST_F(ArrayTest, OutOfBounds) {
    EXPECT_DEATH(array[2], "Index out of range");
    EXPECT_DEATH(array.remove(2), "Index out of range");
}


TEST_F(ArrayTest, AccessOperator) {
    EXPECT_DOUBLE_EQ(array[0]->area(), 12.0);
    EXPECT_DOUBLE_EQ(array[1]->area(), 25.0);
}

TEST_F(ArrayTest, Resize) {
    for (int i = 0; i < 5; ++i) {
        array.add(std::make_shared<Square<int>>(testCenter, 1));
    }

    EXPECT_GT(array.size(), 2);
    EXPECT_NO_THROW({
                        for (size_t i = 0; i < array.size(); ++i) {
                            array[i]->area();
                        }
                    });
}

TEST_F(ArrayTest, ConstArray) {
    const Array<std::shared_ptr<Figure<int>>> &constArray = array;
    EXPECT_DOUBLE_EQ(constArray[0]->area(), 12.0);
    EXPECT_DOUBLE_EQ(constArray.getTotalArea(), 37.0);
}
