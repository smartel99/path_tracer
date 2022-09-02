/**
 * @file    assertion.h
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

#ifndef PATH_TRACER_ASSERTION_H
#define PATH_TRACER_ASSERTION_H

#if defined(DEBUG)
#include "utils/log.h"
#include "utils/macros.h"

#define PT_ASSERT(x, msg, ...)                                                                     \
    do                                                                                             \
    {                                                                                              \
        if (!(x))                                                                                  \
        {                                                                                          \
            PT_CRITICAL("Assertion failed in {}:{}: {}\n\r\t" msg,                                 \
                        __FILE__,                                                                  \
                        __LINE__,                                                                  \
                        #x __VA_OPT__(, ) __VA_ARGS__);                                            \
            BREAKPOINT();                                                                          \
        }                                                                                          \
    } while (0)
#else
#define PT_ASSERT(x, msg, ...)
#endif

#endif    // PATH_TRACER_ASSERTION_H
