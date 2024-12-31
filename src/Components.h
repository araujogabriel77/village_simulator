#pragma once

#include "Vec2.h"

#ifndef COMPONENTS_H
#define COMPONENTS_H


class CTransform {
public:
    Vec2 pos = {0.0, 0.0};

    CTransform(const Vec2 &p)
        : pos(p) {
    }
};

#endif //COMPONENTS_H