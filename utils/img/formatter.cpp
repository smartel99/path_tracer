/**
 * @file    formatter.cpp
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
#include "formatter.h"

#include "png.h"
#include "jpeg.h"

#include "utils/log.h"


bool ImgSaver::Save(const std::string& path)
{
    return Save(m_args.Get<ImgType>("format"), path);
}

bool ImgSaver::Save(ImgType fmt, const std::string& filename)
{
    switch (fmt)
    {
        case ImgType::Png:
            return SaveToPng(filename, m_data, m_args);
        case ImgType::Jpeg:
            return SaveToJpeg(filename, m_data, m_args);
        default:
            PT_ERROR("Unknown image format");
            return false;
    }
}
