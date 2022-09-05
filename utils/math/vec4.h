/**
 * @file    vec4.h
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

#ifndef PATH_TRACER_VEC4_H
#define PATH_TRACER_VEC4_H

#include <cmath>

class Vec4
{
public:
    constexpr Vec4() noexcept = default;
    constexpr Vec4(double x, double y, double z, double w) noexcept : v {x, y, z, w} {}

    [[nodiscard]] constexpr double x() const noexcept { return v[0]; }
    [[nodiscard]] constexpr double y() const noexcept { return v[1]; }
    [[nodiscard]] constexpr double z() const noexcept { return v[2]; }
    [[nodiscard]] constexpr double w() const noexcept { return v[3]; }

    constexpr double  operator[](size_t i) const { return v[i]; }
    constexpr double& operator[](size_t i) { return v[i]; }

    [[nodiscard]] constexpr Vec4 operator-() const noexcept
    {
        return Vec4 {-v[0], -v[1], -v[2], -v[3]};
    }
    [[nodiscard]] constexpr Vec4 operator-(double o) const noexcept
    {
        return Vec4 {v[0] - o, v[1] - o, v[2] - o, v[3] - o};
    }
    [[nodiscard]] constexpr Vec4 operator-(const Vec4& o) const noexcept
    {
        return Vec4 {v[0] - o.v[0], v[1] - o.v[1], v[2] - o.v[2], v[3] - o.v[3]};
    }
    constexpr Vec4& operator-=(double o) noexcept
    {
        v[0] -= o;
        v[1] -= o;
        v[2] -= o;
        v[3] -= o;
        return *this;
    }
    constexpr Vec4& operator-=(const Vec4& o) noexcept
    {
        v[0] -= o.v[0];
        v[1] -= o.v[1];
        v[2] -= o.v[2];
        v[3] -= o.v[3];
        return *this;
    }

    [[nodiscard]] constexpr Vec4 operator+(double o) const noexcept
    {
        return Vec4 {v[0] + o, v[1] + o, v[2] + o, v[3] + o};
    }
    [[nodiscard]] constexpr Vec4 operator+(const Vec4& o) const noexcept
    {
        return Vec4 {v[0] + o.v[0], v[1] + o.v[1], v[2] + o.v[2], v[3] + o.v[3]};
    }
    constexpr Vec4& operator+=(double o) noexcept
    {
        v[0] += o;
        v[1] += o;
        v[2] += o;
        v[3] += o;
        return *this;
    }
    constexpr Vec4& operator+=(const Vec4& o) noexcept
    {
        v[0] += o.v[0];
        v[1] += o.v[1];
        v[2] += o.v[2];
        v[3] += o.v[3];
        return *this;
    }

    [[nodiscard]] constexpr Vec4 operator*(double o) const noexcept
    {
        return Vec4 {v[0] * o, v[1] * o, v[2] * o, v[3] * o};
    }
    [[nodiscard]] constexpr Vec4 operator*(const Vec4& o) const noexcept
    {
        return Vec4 {v[0] * o.v[0], v[1] * o.v[1], v[2] * o.v[2], v[3] * o.v[3]};
    }
    constexpr Vec4& operator*=(double o) noexcept
    {
        v[0] *= o;
        v[1] *= o;
        v[2] *= o;
        v[3] *= o;
        return *this;
    }
    constexpr Vec4& operator*=(const Vec4& o) noexcept
    {
        v[0] *= o.v[0];
        v[1] *= o.v[1];
        v[2] *= o.v[2];
        v[3] *= o.v[3];
        return *this;
    }

    [[nodiscard]] constexpr Vec4 operator/(double o) const noexcept
    {
        return Vec4 {v[0] / o, v[1] / o, v[2] / o, v[3] / o};
    }
    [[nodiscard]] constexpr Vec4 operator/(const Vec4& o) const noexcept
    {
        return Vec4 {v[0] / o.v[0], v[1] / o.v[1], v[2] / o.v[2], v[3] / o.v[3]};
    }
    constexpr Vec4& operator/=(double o) noexcept
    {
        v[0] /= o;
        v[1] /= o;
        v[2] /= o;
        v[3] /= o;
        return *this;
    }
    constexpr Vec4& operator/=(const Vec4& o) noexcept
    {
        v[0] /= o.v[0];
        v[1] /= o.v[1];
        v[2] /= o.v[2];
        v[3] /= o.v[3];
        return *this;
    }

    [[nodiscard]] double           Length() const noexcept { return std::sqrt(LengthSquared()); }
    [[nodiscard]] constexpr double LengthSquared() const noexcept
    {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3];
    }

private:
    double v[4] = {0.0, 0.0, 0.0, 0.0};
};


inline constexpr double Dot(const Vec4& l, const Vec4& r)
{
    return l.x() * r.x() + l.y() * r.y() + l.z() * r.z() + l.w() * r.w();
}


inline constexpr Vec4 UnitVector(const Vec4& v)
{
    return v / v.Length();
}

inline constexpr Vec4 operator*(double t, const Vec4& v)
{
    return {t * v.x(), t * v.y(), t * v.z(), t * v.w()};
}

// Type aliases.
using Point4 = Vec4;    // 4D point.
using Color4 = Vec4;    // RGBA.

#endif    // PATH_TRACER_VEC4_H
