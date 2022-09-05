/**
 * @file    arguments.cpp
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
#include "arguments.h"

#include "utils/log.h"

#include "argengine.hpp"


Arguments::Arguments(int argc, char** argv) noexcept
{
    juzzlin::Argengine ae(argc, argv);

    ae.addOption(
      {"-r", "--output-resolution"},
      [this](const std::string& value)
      {
          size_t      separatorPos = value.find('x');
          std::string width        = value.substr(0, separatorPos);
          std::string height       = value.substr(separatorPos + 1);
          m_params["width"]        = static_cast<uint64_t>(std::stoi(width));
          m_params["height"]       = static_cast<uint64_t>(std::stoi(height));
          PT_TRACE("Resolution: {}x{}",
                   std::get<uint64_t>(m_params["width"]),
                   std::get<uint64_t>(m_params["height"]));
      },
      true,
      "Resolution of the output image",
      "WIDTHxHEIGHT");
    ae.addOption(
      {"-f", "--format"},
      [this](const std::string& value)
      {
          m_params["format"] = ImgTypeFromStr(value);
          PT_TRACE("Format: {}", ImgTypeToStr(std::get<ImgType>(m_params["format"])));
      },
      true,
      "Format of the output image. Currently supported: PNG, JPEG",
      "FMT");

    ae.addOption(
      {"-s", "--samples-per-pixel"},
      [this](const std::string& value)
      { m_params["samples-per-pixel"] = static_cast<uint64_t>(std::stoi(value)); },
      false,
      "Number of samples generated for each pixels. Defaults to 16");

    try
    {
        ae.parse();
    }
    catch (const std::exception& e)
    {
        PT_CRITICAL("Argument parsing error: {}", e.what());
        ae.printHelp();
        std::abort();
    }
}
