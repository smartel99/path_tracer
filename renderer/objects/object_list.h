/**
 * @file    object_list.h
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-09-05
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

#ifndef PATH_TRACER_OBJECT_LIST_H
#define PATH_TRACER_OBJECT_LIST_H

#include "object.h"

#include <memory>
#include <vector>

class ObjectList : public Object
{
public:
    ObjectList() noexcept = default;
    ObjectList(size_t capacity) { m_objects.reserve(capacity); }

    void Clear() noexcept { m_objects.clear(); }

    template<typename T, typename... Args>
    void Add(Args... args) noexcept
        requires std::derived_from<T, Object> && std::constructible_from<T, Args...>
    {
        m_objects.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }

    [[nodiscard]] std::optional<HitRecord> Hit(const Ray& r,
                                               double     tMin,
                                               double     tMax) const noexcept override;

private:
    std::vector<std::unique_ptr<Object>> m_objects = {};
};

#endif    // PATH_TRACER_OBJECT_LIST_H
