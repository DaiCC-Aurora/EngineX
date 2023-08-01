/*
 * @Author DaiCC
 * @brief Color
 * @file EColor.cpp
 * @date 2023/7/29
 * @version deb0.0.1
 */

#include "EColor.h"

namespace Engine {

    EColor::EColor() noexcept : r(0), g(0), b(0), a(0) {}

    EColor::EColor(int red, int green, int blue, int alpha) noexcept :
        r(red),
        g(green),
        b(blue),
        a(alpha)
    {}

    int EColor::alpha() const { return this->a; }
    int EColor::red() const { return this->r; }
    int EColor::green() const { return this->g; }
    int EColor::blue() const { return this->b; }

    void EColor::setAlpha(int alpha) { this->a = alpha; }
    void EColor::setRed(int red) { this->r = red; }
    void EColor::setGreen(int green) { this->g = green; }
    void EColor::setBlue(int blue) { this->b = blue; }
}