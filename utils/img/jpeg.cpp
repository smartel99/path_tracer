/**
 * @file    jpeg.cpp
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
#include "jpeg.h"
#include "utils/args/arguments.h"
#include "utils/log.h"

#include "stb/stb_image_write.h"


bool SaveToJpeg(const std::string& path, const std::vector<uint8_t>& data, const Arguments& args)
{
    static constexpr int channelCount = 4;    // RGBA.
    static constexpr int quality = 100;       // 1-100, higher number = higher quality, bigger file.
    int                  res          = stbi_write_jpg(path.c_str(),
                             static_cast<int>(args.Get<uint64_t>("width")),
                             static_cast<int>(args.Get<uint64_t>("height")),
                             channelCount,
                             data.data(),
                             quality);

    if (res != 0)
    {
        PT_ERROR("stbi_write_jpeg returned {}", res);
        return false;
    }
    else
    {
        return true;
    }
}