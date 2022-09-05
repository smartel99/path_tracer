/**
 * @file    hit_record.h
 * @author  Samuel Martel
 * @p       https://github.com/smartel99
 * @date    2022-09-04
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

#ifndef PATH_TRACER_HIT_RECORD_H
#define PATH_TRACER_HIT_RECORD_H

#include "utils/math/vec3.h"
#include "renderer/ray.h"

struct HitRecord
{
    Point3 Point     = {};
    Vec3   Normal    = {};
    double T         = {};
    bool   FrontFace = false;

    void SetFaceNormal(const Ray& r, const Vec3& outwardNormal)
    {
        FrontFace = Dot(r.Direction(), outwardNormal) < 0;
        Normal    = FrontFace ? outwardNormal : -outwardNormal;
    }
};

#endif    // PATH_TRACER_HIT_RECORD_H
