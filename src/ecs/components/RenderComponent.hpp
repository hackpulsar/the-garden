#ifndef RENDER_COMPONENT_H
#define RENDER_COMPONENT_H

#include "../ecs.hpp"
#include "../../texture.hpp"
#include "../../texture_manager.h"
#include "PositionComponent.hpp"
#include "../../definitions.hpp"

#include <SDL2/SDL_render.h>
#include <cassert>

namespace Core::ECS
{

class RenderComponent : public Component
{
public:
    RenderComponent(TextureManager& textureManager, const std::string& sTextureKey)
        : m_pTexture(textureManager.get_texture(sTextureKey))
    {

    }
    ~RenderComponent() = default;

    void Init() override
    {
        assert(
            m_pEntity->hasComponent<PositionComponent>() &&
            "Entity you want to render does not have a PositionComponent."
        );
        m_pPositionComponent = m_pEntity->getComponent<PositionComponent>();
    }

    void Update() override { }

    void Render(SDL_Renderer* pRenderer)
    {
        m_DestinationRect = {
            int(m_pPositionComponent->getPosition().m_X),
            int(m_pPositionComponent->getPosition().m_Y),
            TILE_SCREEN_SIZE, TILE_SCREEN_SIZE
        };

        SDL_RenderCopy(
            pRenderer,
            m_pTexture.m_pSpriteSheet,
            &m_pTexture.m_ClipRect,
            &m_DestinationRect
        );
    }

private:
    PositionComponent* m_pPositionComponent;
    Texture m_pTexture;
    SDL_Rect m_DestinationRect; 

};

}

#endif // RENDER_COMPONENT_H
