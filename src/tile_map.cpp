#include "tile_map.h"

#include "definitions.hpp"
#include <_types/_uint16_t.h>

#include "log.h"
#include <string>

namespace Core
{

TileMap::TileMap()
{
    // Set every tile's coordinates
    for (int i = 0; i < TILE_MAP_SIZE; i++)
    {
        m_TileMap.push_back(std::vector<Tile>(TILE_MAP_SIZE));
        for (int j = 0; j < TILE_MAP_SIZE; j++)
        {
            m_TileMap[i].push_back(Tile{});

            m_TileMap[i][j].m_MapPos = vec2<uint16_t>{ uint16_t(j), uint16_t(i) };
            m_TileMap[i][j].m_ScreenPos = vec2<int>{ j * TILE_SCREEN_SIZE, i * TILE_SCREEN_SIZE };
        }
    }
}

TileMap::~TileMap()
{
    m_TileMap.clear();
}

void TileMap::Render(SDL_Renderer* pRenderer)
{
    // Render every tile
    for (int i = 0; i < TILE_MAP_SIZE; i++)
    {
        for (int j = 0; j < TILE_MAP_SIZE; j++)
        {
            SDL_Rect rect = { 
                m_TileMap[i][j].m_ScreenPos.x,
                m_TileMap[i][j].m_ScreenPos.y, 
                TILE_SCREEN_SIZE, TILE_SCREEN_SIZE 
            };

            // Debug purposes only
            SDL_SetRenderDrawColor(pRenderer, rand() % 255, rand() % 255, rand() % 255, 255);
            SDL_RenderFillRect(pRenderer, &rect);
        }
    }
}

}

