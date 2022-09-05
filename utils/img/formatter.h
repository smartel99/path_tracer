/**
 * @file    formatter.h
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

#ifndef PATH_TRACER_FORMATTER_H
#define PATH_TRACER_FORMATTER_H

#include "utils/args/arguments.h"
#include "types.h"

#include <vector>
#include <string>

class ImgSaver
{
public:
    ImgSaver(const std::vector<uint8_t>& data, const Arguments& args)
    : m_data(data), m_args(args)
    {
    }

    bool Save(const std::string& filename);
    bool Save(ImgType fmt, const std::string& filename);
private:
    const std::vector<uint8_t>& m_data;
    const Arguments&            m_args;

};


#endif    // PATH_TRACER_FORMATTER_H
