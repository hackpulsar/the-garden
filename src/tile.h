#ifndef TILE_H
#define TILE_H

#include "texture.hpp"

#include "vec.hpp"
#include <_types/_uint16_t.h>

namespace Core
{

struct Tile
{
    vec2<uint16_t> m_MapPos;
    vec2<int> m_ScreenPos;

    Texture m_Texture;
};

}

#endif // TILE_H
