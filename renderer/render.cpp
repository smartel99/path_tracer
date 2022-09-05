/**
 * @file    render.cpp
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
#include "render.h"

#include "utils/assertion.h"
#include "utils/math/random.h"

#include <chrono>

Render::Render(const Arguments& args)
: m_width(args.Get<uint64_t>("width")),
  m_height(args.Get<uint64_t>("height")),
  m_samplesPerPixel(args.Get<uint64_t>("samples-per-pixel", 16)),
  m_data(m_height * m_width * s_channelCount)
{
    double aspectRatio = static_cast<double>(m_width) / static_cast<double>(m_height);
    double vpHeight    = 2.0;
    double vpWidth     = aspectRatio * vpHeight;
    m_camera           = Camera(vpWidth, vpHeight);

    PT_TRACE("Initializing buffer...");
    // Default initialize the frame buffer with a color pattern.
    for (size_t y = 0; y < m_height; y++)
    {
        for (size_t x = 0; x < m_width; x++)
        {
            SetColorAt(x, y, {1.0, 0.0, 1.0, 1.0});
        }
    }
    PT_TRACE("Done!");
}

const std::vector<uint8_t>& Render::Finalize()
{
    auto start = std::chrono::steady_clock::now();

    // Do the render.
    for (size_t y = 0; y < m_height; y++)
    {
        PT_TRACE("Rendering scanline {} out of {}", y + 1, m_height);
        for (size_t x = 0; x < m_width; x++)
        {
            Color4 color = {};
            for (size_t p = 0; p < m_samplesPerPixel; p++)
            {
                double u =
                  (static_cast<double>(x) + MakeRandomDouble()) / static_cast<double>(m_width - 1);
                double v =
                  (static_cast<double>(y) + MakeRandomDouble()) / static_cast<double>(m_height - 1);
                Ray r = m_camera.TraceRayAt(u, v);
                color += RayColor(r, m_objects);
            }
            SetColorAt(x, y, color, m_samplesPerPixel);
        }
    }

    auto stop  = std::chrono::steady_clock::now();
    auto delta = stop - start;

    PT_INFO("Render done, took {}ms", std::chrono::duration<double, std::milli>(delta).count());

    return m_data;
}

void Render::SetColorAt(size_t x, size_t y, const Color4& col, size_t samplesPerPixel)
{
    size_t at = ((y * m_width) + x) * s_channelCount;
    PT_ASSERT(at < m_data.size(), "Invalid position ({}, {})", x, y);
    double scale = 1.0 / static_cast<double>(samplesPerPixel);

    for (size_t i = 0; i < s_channelCount; i++)
    {
        double sample  = col[i] * scale;
        m_data[at + i] = static_cast<uint8_t>(256 * std::clamp(sample, 0.0, 0.999));
    }
}

Color4 Render::GetColorAt(size_t x, size_t y) const
{
    size_t at = ((y * m_width) + x) * s_channelCount;
    PT_ASSERT(at < m_data.size(), "Invalid position ({}, {})", x, y);

    return {m_data[at] / 255.999,
            m_data[at + 1] / 255.999,
            m_data[at + 2] / 255.999,
            m_data[at + 3] / 255.999};
}


Color4 Render::RayColor(const Ray& r, const Object& world)
{
    auto hit = world.Hit(r, 0.0, std::numeric_limits<double>::infinity());
    if (hit)
    {
        // give a value of 2 for the alpha, so it becomes 1 with the * 0.5.
        return 0.5 *
               Color4 {1.0 + hit->Normal.x(), 1.0 + hit->Normal.y(), 1.0 + hit->Normal.z(), 2.0};
    }
    Vec3   unitDirection = UnitVector(r.Direction());
    double t             = 0.5 * (unitDirection.y() + 1.0);
    return (1.0 - t) * Color4 {1.0, 1.0, 1.0, 1.0} + t * Color4 {0.5, 0.7, 1.0, 1.0};
}