#include "ecs.hpp"

#include <memory>

using namespace Core;

// === Entity implementation ===

void ECS::Entity::Update()
{
    for (auto& c : m_Components)
        c->Update();
}

bool ECS::Entity::isActive() const { return m_bActive; }
void ECS::Entity::Destroy() { m_bActive = false; }

