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

Render::Render(const Arguments& args)
: m_width(args.Get<uint64_t>("width")),
  m_height(args.Get<uint64_t>("height")),
  m_data(m_height * m_width * s_channelCount)
{
    m_data.clear();
    // Default initialize the frame buffer with a color pattern.
    for (size_t y = 0; y < m_height; y++)
    {
        for (size_t x = 0; x < m_width; x++)
        {
            auto          r = static_cast<double>(x) / static_cast<double>((m_width - 1));
            auto          g = static_cast<double>(y) / static_cast<double>((m_height - 1));
            const uint8_t b = 64;     // Constant slight blue.
            const uint8_t a = 255;    // always opaque.

            m_data.emplace_back(static_cast<uint8_t>(256 * r));
            m_data.emplace_back(static_cast<uint8_t>(256 * g));
            m_data.push_back(b);
            m_data.push_back(a);
        }
    }
}

const std::vector<uint8_t>& Render::Finalize()
{
    // Do the render.
    return m_data;
}
