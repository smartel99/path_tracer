/**
 * @file    sphere.cpp
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
#include "sphere.h"

std::optional<HitRecord> Sphere::Hit(const Ray& r, double tMin, double tMax) const noexcept
{
    Vec3   oc    = r.Origin() - m_center;
    double a     = r.Direction().LengthSquared();
    double halfB = Dot(oc, r.Direction());
    double c     = oc.LengthSquared() - m_radius * m_radius;

    double discriminant = halfB * halfB - a * c;
    if (discriminant < 0.0)
    {
        return {};
    }
    double sqrtd = std::sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (-halfB - sqrtd) / a;
    if (root < tMin || root > tMax)
    {
        root = (-halfB + sqrtd) / a;
        if (root < tMin || root > tMax)
        {
            return {};
        }
    }

    HitRecord hr;
    hr.Point           = r.At(root);
    hr.T               = root;
    Vec3 outwardNormal = (hr.Point - m_center) / m_radius;
    hr.SetFaceNormal(r, outwardNormal);

    return hr;
}
