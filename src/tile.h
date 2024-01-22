#ifndef TILE_H
#define TILE_H

#include <SDL2/SDL_render.h>

#include "vec.hpp"
#include <_types/_uint16_t.h>

namespace Core
{

struct Tile
{
    vec2<uint16_t> m_MapPos;
    vec2<int> m_ScreenPos;

    SDL_Texture* m_pTexture;
};

}

#endif // TILE_H
