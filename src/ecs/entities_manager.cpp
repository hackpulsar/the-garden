#include "entities_manager.h"

#include "components/RenderComponent.hpp"

using namespace Core;

void ECS::EntitiesManager::Update()
{
    for (auto& e : m_Entities)
        e->Update();
}

void ECS::EntitiesManager::Render(SDL_Renderer* pRenderer)
{
    for (auto& e : m_Entities)
    {
        if (e->hasComponent<ECS::RenderComponent>())
            e->getComponent<ECS::RenderComponent>()->Render(pRenderer);
    }
}

void ECS::EntitiesManager::Refresh()
{
    m_Entities.erase(
        std::remove_if(
            std::begin(m_Entities), 
            std::end(m_Entities), 
            [](const std::unique_ptr<Entity>& mEntity)
            {
                return !mEntity->isActive();
            }
        ), 
        std::end(m_Entities)
    );
}

ECS::Entity& ECS::EntitiesManager::AddEntity()
{
    Entity* e = new Entity();
    std::unique_ptr<Entity> upEntity{e};
    m_Entities.emplace_back(std::move(upEntity));
    return *e;
}

