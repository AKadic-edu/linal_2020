#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#include <cmath>

namespace math {
    inline double pi()
    {
        return std::atan(1) * 4.0;
    }

    template<typename T>
    T radians(const T& angle)
    {
        return static_cast<T>(angle * (pi() / 180.0f));
    }
}

#endif // !MATH_UTILS_HPP