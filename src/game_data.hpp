#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

#include "tile_map.h"
#include "texture_manager.h"

namespace Core
{

struct GameData
{
    TileMap* m_TileMap = nullptr;
    TextureManager* m_TextureManager = nullptr;

    ~GameData()
    {
        delete m_TileMap;
        delete m_TextureManager;
    }
};

}

#endif // GAME_DATA_HPP
