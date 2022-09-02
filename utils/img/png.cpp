/**
 * @file    png.cpp
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-08-28
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
#include "png.h"
#include "utils/args/arguments.h"
#include "utils/log.h"

#include "stb/stb_image_write.h"


bool SaveToPng(const std::string& path, const std::vector<uint8_t>& data, const Arguments& args)
{
    static constexpr int channelCount = 4;    // RGBA.
    int                  width        = static_cast<int>(args.Get<uint64_t>("width"));
    int                  res          = stbi_write_png(path.c_str(),
                             width,
                             static_cast<int>(args.Get<uint64_t>("height")),
                             channelCount,
                             data.data(),
                             width * channelCount);

    if (res != 0)
    {
        PT_ERROR("stbi_write_png returned {}", res);
        return false;
    }
    else
    {
        return true;
    }
}
