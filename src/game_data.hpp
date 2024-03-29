#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

#include "tile_map.h"
#include "texture_manager.h"
#include "ecs/entities_manager.h"

namespace Core
{

struct GameData
{
    TileMap* m_TileMap = nullptr;
    TextureManager* m_TextureManager = nullptr;
    ECS::EntitiesManager* m_EntitiesManager = nullptr;

    ~GameData()
    {
        delete m_TileMap;
        delete m_TextureManager;
        delete m_EntitiesManager;
    }
};

}

#endif // GAME_DATA_HPP
