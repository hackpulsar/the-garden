#ifndef GAME_DATA_HPP
#define GAME_DATA_HPP

#include "tile_map.h"

namespace Core
{

struct GameData
{
    TileMap* m_TileMap = nullptr;
};

}

#endif // GAME_DATA_HPP
