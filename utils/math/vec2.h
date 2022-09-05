/**
 * @file    vec2.h
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-09-03
 *
 * @brief
 ******************************************************************************
 * Copyright (C) 2022  Samuel Martel
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef PATH_TRACER_VEC2_H
#define PATH_TRACER_VEC2_H

#include <cmath>

class Vec2
{
public:
    constexpr Vec2() noexcept = default;
    constexpr Vec2(double x, double y) noexcept : v {x, y} {}

    [[nodiscard]] constexpr double x() const noexcept { return v[0]; }
    [[nodiscard]] constexpr double y() const noexcept { return v[1]; }

    constexpr double  operator[](size_t i) const { return v[i]; }
    constexpr double& operator[](size_t i) { return v[i]; }

    [[nodiscard]] constexpr Vec2 operator-() const noexcept { return Vec2 {-v[0], -v[1]}; }
    [[nodiscard]] constexpr Vec2 operator-(double o) const noexcept
    {
        return Vec2 {v[0] - o, v[1] - o};
    }
    [[nodiscard]] constexpr Vec2 operator-(const Vec2& o) const noexcept
    {
        return Vec2 {v[0] - o.v[0], v[1] - o.v[1]};
    }
    constexpr Vec2& operator-=(double o) noexcept
    {
        v[0] -= o;
        v[1] -= o;
        return *this;
    }
    constexpr Vec2& operator-=(const Vec2& o) noexcept
    {
        v[0] -= o.v[0];
        v[1] -= o.v[1];
        return *this;
    }

    [[nodiscard]] constexpr Vec2 operator+(double o) const noexcept
    {
        return Vec2 {v[0] + o, v[1] + o};
    }
    [[nodiscard]] constexpr Vec2 operator+(const Vec2& o) const noexcept
    {
        return Vec2 {v[0] + o.v[0], v[1] + o.v[1]};
    }
    constexpr Vec2& operator+=(double o) noexcept
    {
        v[0] += o;
        v[1] += o;
        return *this;
    }
    constexpr Vec2& operator+=(const Vec2& o) noexcept
    {
        v[0] += o.v[0];
        v[1] += o.v[1];
        return *this;
    }

    [[nodiscard]] constexpr Vec2 operator*(double o) const noexcept
    {
        return Vec2 {v[0] * o, v[1] * o};
    }
    [[nodiscard]] constexpr Vec2 operator*(const Vec2& o) const noexcept
    {
        return Vec2 {v[0] * o.v[0], v[1] * o.v[1]};
    }
    constexpr Vec2& operator*=(double o) noexcept
    {
        v[0] *= o;
        v[1] *= o;
        return *this;
    }
    constexpr Vec2& operator*=(const Vec2& o) noexcept
    {
        v[0] *= o.v[0];
        v[1] *= o.v[1];
        return *this;
    }

    [[nodiscard]] constexpr Vec2 operator/(double o) const noexcept
    {
        return Vec2 {v[0] / o, v[1] / o};
    }
    [[nodiscard]] constexpr Vec2 operator/(const Vec2& o) const noexcept
    {
        return Vec2 {v[0] / o.v[0], v[1] / o.v[1]};
    }
    constexpr Vec2& operator/=(double o) noexcept
    {
        v[0] /= o;
        v[1] /= o;
        return *this;
    }
    constexpr Vec2& operator/=(const Vec2& o) noexcept
    {
        v[0] /= o.v[0];
        v[1] /= o.v[1];
        return *this;
    }

    [[nodiscard]] double           Length() const noexcept { return std::sqrt(LengthSquared()); }
    [[nodiscard]] constexpr double LengthSquared() const noexcept
    {
        return v[0] * v[0] + v[1] * v[1];
    }

private:
    double v[2] = {0.0, 0.0};
};

// Type aliases.
using Point2 = Vec2;    // 2D point.

#endif    // PATH_TRACER_VEC2_H
