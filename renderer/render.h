/**
 * @file    render.h
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-09-02
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

#ifndef PATH_TRACER_RENDER_H
#define PATH_TRACER_RENDER_H

#include "utils/img/formatter.h"
#include "utils/args/arguments.h"

#include <vector>

class Render
{
public:
    Render(const Arguments& args);

    const std::vector<uint8_t>& Finalize();

    [[nodiscard]] const std::vector<uint8_t>& GetData() const noexcept { return m_data; }
    [[nodiscard]] size_t                      GetWidth() const noexcept { return m_width; }
    [[nodiscard]] size_t                      GetHeight() const noexcept { return m_height; }

private:
    static constexpr size_t s_channelCount = 4; //!< Working in RGBA.

    size_t m_width  = 0;
    size_t m_height = 0;

    std::vector<uint8_t> m_data = {};
};

#endif    // PATH_TRACER_RENDER_H