/**
 * @file    log.h
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

#ifndef PATH_TRACER_LOG_H
#define PATH_TRACER_LOG_H

#include "spdlog/spdlog.h"

class Log
{
public:
    static void Init();

    static spdlog::logger& GetLogger() { return *s_logger; }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

#define PT_TRACE(...)       ::Log::GetLogger().trace(__VA_ARGS__)
#define PT_INFO(...)        ::Log::GetLogger().info(__VA_ARGS__)
#define PT_WARN(...)        ::Log::GetLogger().warn(__VA_ARGS__)
#define PT_ERROR(...)       ::Log::GetLogger().error(__VA_ARGS__)
#define PT_CRITICAL(...)    ::Log::GetLogger().critical(__VA_ARGS__)

#endif    // PATH_TRACER_LOG_H
