/**
 * @file    types.cpp
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
#include "types.h"

#include "utils/log.h"

ImgType ImgTypeFromStr(const std::string& str)
{
    using namespace std::string_literals;
    if (str == "PNG"s)
    {
        return ImgType::Png;
    }
    else if (str == "JPEG"s)
    {
        return ImgType::Jpeg;
    }
    else
    {
        throw std::runtime_error(fmt::format("Unrecognized image format '{}'", str));
    }
}

std::string ImgTypeToStr(ImgType type)
{
    using namespace std::string_literals;

    switch (type)
    {
        case ImgType::Png:
            return "PNG"s;
        case ImgType::Jpeg:
            return "JPEG"s;
        default:
            return "<UNKNOWN>";
    }
}
