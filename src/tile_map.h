#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <SDL_render.h>
#include <vector>
#include "tile.h"

namespace Core
{

class TileMap
{
public:
    TileMap();
    ~TileMap();

    void Render(SDL_Renderer* pRenderer);

private:
    std::vector<std::vector<Tile>> m_TileMap;

};

}

#endif // TILE_MAP_H
