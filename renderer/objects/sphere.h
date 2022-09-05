/**
 * @file    sphere.h
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

#ifndef PATH_TRACER_SPHERE_H
#define PATH_TRACER_SPHERE_H

#include "object.h"

class Sphere : public Object
{
public:
    constexpr Sphere() noexcept = default;
    constexpr Sphere(const Point3& center, double radius) noexcept
    : m_center(center), m_radius(radius)
    {
    }

    [[nodiscard]] std::optional<HitRecord> Hit(const Ray& r, double tMin, double tMax) const
      noexcept override;


private:
    Point3 m_center = {};
    double m_radius = {};
};
#endif    // PATH_TRACER_SPHERE_H
