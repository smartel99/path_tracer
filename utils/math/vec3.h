/**
 * @file    vec3.h
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

#ifndef PATH_TRACER_VEC3_H
#define PATH_TRACER_VEC3_H

#include <cmath>

class Vec3
{
public:
    constexpr Vec3() noexcept = default;
    constexpr Vec3(double x, double y, double z) noexcept : v {x, y, z} {}

    [[nodiscard]] constexpr double x() const noexcept { return v[0]; }
    [[nodiscard]] constexpr double y() const noexcept { return v[1]; }
    [[nodiscard]] constexpr double z() const noexcept { return v[2]; }

    constexpr double  operator[](size_t i) const { return v[i]; }
    constexpr double& operator[](size_t i) { return v[i]; }

    [[nodiscard]] constexpr Vec3 operator-() const noexcept { return Vec3 {-v[0], -v[1], -v[2]}; }
    [[nodiscard]] constexpr Vec3 operator-(double o) const noexcept
    {
        return Vec3 {v[0] - o, v[1] - o, v[2] - o};
    }
    [[nodiscard]] constexpr Vec3 operator-(const Vec3& o) const noexcept
    {
        return Vec3 {v[0] - o.v[0], v[1] - o.v[1], v[2] - o.v[2]};
    }
    constexpr Vec3& operator-=(double o) noexcept
    {
        v[0] -= o;
        v[1] -= o;
        v[2] -= o;
        return *this;
    }
    constexpr Vec3& operator-=(const Vec3& o) noexcept
    {
        v[0] -= o.v[0];
        v[1] -= o.v[1];
        v[2] -= o.v[2];
        return *this;
    }

    [[nodiscard]] constexpr Vec3 operator+(double o) const noexcept
    {
        return Vec3 {v[0] + o, v[1] + o, v[2] + o};
    }
    [[nodiscard]] constexpr Vec3 operator+(const Vec3& o) const noexcept
    {
        return Vec3 {v[0] + o.v[0], v[1] + o.v[1], v[2] + o.v[2]};
    }
    constexpr Vec3& operator+=(double o) noexcept
    {
        v[0] += o;
        v[1] += o;
        v[2] += o;
        return *this;
    }
    constexpr Vec3& operator+=(const Vec3& o) noexcept
    {
        v[0] += o.v[0];
        v[1] += o.v[1];
        v[2] += o.v[2];
        return *this;
    }

    [[nodiscard]] constexpr Vec3 operator*(double o) const noexcept
    {
        return Vec3 {v[0] * o, v[1] * o, v[2] * o};
    }
    [[nodiscard]] constexpr Vec3 operator*(const Vec3& o) const noexcept
    {
        return Vec3 {v[0] * o.v[0], v[1] * o.v[1], v[2] * o.v[2]};
    }
    constexpr Vec3& operator*=(double o) noexcept
    {
        v[0] *= o;
        v[1] *= o;
        v[2] *= o;
        return *this;
    }
    constexpr Vec3& operator*=(const Vec3& o) noexcept
    {
        v[0] *= o.v[0];
        v[1] *= o.v[1];
        v[2] *= o.v[2];
        return *this;
    }

    [[nodiscard]] constexpr Vec3 operator/(double o) const noexcept
    {
        return Vec3 {v[0] / o, v[1] / o, v[2] / o};
    }
    [[nodiscard]] constexpr Vec3 operator/(const Vec3& o) const noexcept
    {
        return Vec3 {v[0] / o.v[0], v[1] / o.v[1], v[2] / o.v[2]};
    }
    constexpr Vec3& operator/=(double o) noexcept
    {
        v[0] /= o;
        v[1] /= o;
        v[2] /= o;
        return *this;
    }
    constexpr Vec3& operator/=(const Vec3& o) noexcept
    {
        v[0] /= o.v[0];
        v[1] /= o.v[1];
        v[2] /= o.v[2];
        return *this;
    }

    [[nodiscard]] double           Length() const noexcept { return std::sqrt(LengthSquared()); }
    [[nodiscard]] constexpr double LengthSquared() const noexcept
    {
        return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
    }

private:
    double v[3] = {0.0, 0.0, 0.0};
};


inline constexpr double Dot(const Vec3& l, const Vec3& r)
{
    return l.x() * r.x() + l.y() * r.y() + l.z() * r.z();
}

inline constexpr Vec3 Cross(const Vec3& l, const Vec3& r)
{
    return Vec3 {
      l.y() * r.z() - l.z() * r.y(), l.z() * r.x() - l.x() * r.z(), l.x() * r.y() - l.y() * r.x()};
}

inline constexpr Vec3 UnitVector(const Vec3& v)
{
    return v / v.Length();
}

inline constexpr Vec3 operator*(double t, const Vec3& v)
{
    return {t * v.x(), t * v.y(), t * v.z()};
}

// Type aliases.
using Point3 = Vec3;    // 3D point.
using Color3 = Vec3;    // RGB.

#endif    // PATH_TRACER_VEC3_H
