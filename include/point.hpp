#ifndef LAB_OOP_4_POINT_HPP
#define LAB_OOP_4_POINT_HPP
#include <concepts>
#include <type_traits>

template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

template<Scalar T>
class Point {
private:
    T x, y;

public:
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T x_) { x = x_; }
    void setY(T y_) { y = y_; }
};

#endif //LAB_OOP_4_POINT_HPP