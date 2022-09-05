/**
 * @file    camera.h
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

#ifndef PATH_TRACER_CAMERA_H
#define PATH_TRACER_CAMERA_H

#include "utils/math/vec3.h"
#include "renderer/ray.h"

class Camera
{
public:
    constexpr Camera() noexcept = default;
    constexpr Camera(double      width,
                     double      height,
                     double      focalLength = 1.0,
                     const Vec3& origin      = {0.0, 0.0, 0.0}) noexcept
    : m_vpWidth(width),
      m_vpHeight(height),
      m_focalLength(focalLength),
      m_origin(origin),
      m_horizontal(m_vpWidth, 0.0, 0.0),
      m_vertical(0.0, m_vpHeight, 0.0),
      m_lowerLeftCorner(m_origin - m_horizontal / 2.0 - m_vertical / 2.0 -
                        Vec3 {0.0, 0.0, m_focalLength})
    {
    }

    [[nodiscard]] constexpr Ray TraceRayAt(double u, double v) const noexcept
    {
        return {m_origin, m_lowerLeftCorner + u * m_horizontal + v * m_vertical - m_origin};
    }

private:
    double m_vpWidth     = 0.0;
    double m_vpHeight    = 0.0;
    double m_focalLength = 0.0;

    Vec3 m_origin          = {};
    Vec3 m_horizontal      = {};
    Vec3 m_vertical        = {};
    Vec3 m_lowerLeftCorner = {};
};
#endif    // PATH_TRACER_CAMERA_H
