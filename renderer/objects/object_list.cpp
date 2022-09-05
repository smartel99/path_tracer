/**
 * @file    object_list.cpp
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
#include "object_list.h"


std::optional<HitRecord> ObjectList::Hit(const Ray& r, double tMin, double tMax) const noexcept
{
    std::optional<HitRecord> closestHit;
    double                   closest = tMax;

    for (const auto& object : m_objects)
    {
        auto hr = object->Hit(r, tMin, tMax);
        if (hr)
        {
            if (hr->T <= closest)
            {
                closest    = hr->T;
                closestHit = hr;
            }
        }
    }

    return closestHit;
}
