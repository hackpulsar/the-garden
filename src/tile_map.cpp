#include "tile_map.h"

#include "definitions.hpp"
#include "texture_manager.h"
#include <_types/_uint16_t.h>

namespace Core
{

TileMap::TileMap()
{  }

TileMap::~TileMap()
{
    for (auto& row : m_TileMap)
        row.clear();
    m_TileMap.clear();
}

void TileMap::Init(const TextureManager& textureManager)
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
            m_TileMap[i][j].m_Texture = textureManager.get_texture("grass");
        }
    }
}

void TileMap::Render(SDL_Renderer* pRenderer)
{
    // Render every tile
    for (int i = 0; i < TILE_MAP_SIZE; i++)
    {
        for (int j = 0; j < TILE_MAP_SIZE; j++)
        {
            SDL_Rect rect = { 
                m_TileMap[i][j].m_ScreenPos.m_X,
                m_TileMap[i][j].m_ScreenPos.m_Y, 
                TILE_SCREEN_SIZE, TILE_SCREEN_SIZE 
            };

            // Debug purposes only
            SDL_RenderCopy(
                pRenderer, 
                m_TileMap[i][j].m_Texture.m_pSpriteSheet, 
                &m_TileMap[i][j].m_Texture.m_ClipRect,
                &rect
            );
        }
    }
}

}

