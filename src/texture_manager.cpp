#include "texture_manager.h"

#include <SDL2/SDL_image.h>
#include "log.h"

void Core::TextureManager::load(const std::string& key, const std::string& sPath, SDL_Renderer* pRenderer)
{
    SDL_Texture* texture = IMG_LoadTexture(pRenderer, sPath.c_str());
    if (texture != NULL)
        m_Textures[key] = texture;
    else
        Core::LOG(Core::LogType::Error, std::string("Failed to load texture from " + sPath).c_str());
}

SDL_Texture* Core::TextureManager::get(const std::string& key) const
{
    return m_Textures.at(key);
}

Core::TextureManager::~TextureManager()
{
    for (auto& t : m_Textures)
         SDL_DestroyTexture(t.second);
}

