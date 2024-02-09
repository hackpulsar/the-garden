#include "texture_manager.h"

#include <SDL2/SDL_image.h>
#include "log.h"

void Core::TextureManager::load_spritesheet(const std::string& sKey, const std::string& sPath, SDL_Renderer* pRenderer)
{
    SDL_Texture* texture = IMG_LoadTexture(pRenderer, sPath.c_str());
    if (texture != NULL)
        m_Spritesheets[sKey] = texture;
    else
        Core::LOG(Core::LogType::Error, std::string("Failed to load spritesheet from " + sPath).c_str());
}

void Core::TextureManager::load_texture(const std::string& sKey, const std::string& sSpritesheetKey, SDL_Rect clip)
{
    m_Textures[sKey] = { this->get_spritesheet(sSpritesheetKey), clip };
}

SDL_Texture* Core::TextureManager::get_spritesheet(const std::string& sKey) const
{
    return m_Spritesheets.at(sKey);
}

Core::Texture Core::TextureManager::get_texture(const std::string& sKey) const
{
    return m_Textures.at(sKey);
}

Core::TextureManager::~TextureManager()
{
    for (auto& t : m_Spritesheets)
         SDL_DestroyTexture(t.second);
}

