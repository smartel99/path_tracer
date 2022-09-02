/**
 * @file    arguments.h
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

#ifndef PATH_TRACER_ARGUMENTS_H
#define PATH_TRACER_ARGUMENTS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <variant>

#include "utils/img/types.h"


class Arguments
{
public:
    using Param = std::variant<std::monostate,
                               bool,
                               uint64_t,
                               double,
                               std::string,
                               std::vector<std::string>,
                               ImgType>;

    /**
     * @brief Parses the arguments passed to the process through the command line into the
     * various options required by the program.
     * @param argc The number of arguments.
     * @param argv The arguments.
     */
    Arguments(int argc, char** argv) noexcept;

    template<typename T>
    [[nodiscard]] T Get(const std::string& flag, T defaultValue = {}) const
    {
        if (m_params.contains(flag) && std::holds_alternative<T>(m_params.at(flag)))
        {
            return std::get<T>(m_params.at(flag));
        }
        return defaultValue;
    }

private:
    std::unordered_map<std::string, Param> m_params = {};
};

#endif    // PATH_TRACER_ARGUMENTS_H
