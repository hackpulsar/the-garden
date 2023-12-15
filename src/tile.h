#ifndef TILE_H
#define TILE_H

#include "vec.hpp"
#include <_types/_uint16_t.h>

namespace Core
{

struct Tile
{
    vec2<uint16_t> m_MapPos;
    vec2<int> m_ScreenPos;
};

}

#endif // TILE_H
