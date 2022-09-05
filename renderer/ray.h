/**
 * @file    ray.h
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-09-04
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

#ifndef PATH_TRACER_RAY_H
#define PATH_TRACER_RAY_H

#include "utils/math/vec3.h"

class Ray
{
public:
    constexpr Ray() noexcept = default;
    constexpr Ray(const Point3& origin, const Vec3& direction) noexcept
    : m_origin(origin), m_direction(direction)
    {
    }

    [[nodiscard]] constexpr const Point3& Origin() const noexcept { return m_origin; }
    [[nodiscard]] constexpr const Vec3&   Direction() const noexcept { return m_direction; }

    [[nodiscard]] constexpr Point3 At(double t) const noexcept
    {
        return m_origin + (m_direction * t);
    }

private:
    Point3 m_origin    = {};    //!< Origin of the ray in 3D space.
    Vec3   m_direction = {};    //!< Direction of the ray in 3D space.
};

#endif    // PATH_TRACER_RAY_H
