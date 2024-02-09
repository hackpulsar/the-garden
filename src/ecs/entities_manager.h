#ifndef ENTITIES_MANAGER_H
#define ENTITIES_MANAGER_H

#include "ecs.hpp"
#include <SDL2/SDL_render.h>

namespace Core::ECS
{

class EntitiesManager
{
private:
    std::vector<std::unique_ptr<Entity>> m_Entities;

public:
    EntitiesManager() = default;
    ~EntitiesManager() = default;

    void Update();
    void Render(SDL_Renderer* pRenderer);
    void Refresh();
    Entity& AddEntity();

};

}

#endif // ENTITIES_MANAGER_H
