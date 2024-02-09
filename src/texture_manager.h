#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <unordered_map>
#include <string>

#include "texture.hpp"

namespace Core
{

struct TextureManager
{
    std::unordered_map<std::string, SDL_Texture*> m_Spritesheets;
    std::unordered_map<std::string, Texture> m_Textures;

    void load_spritesheet(const std::string& sKey, const std::string& sPath, SDL_Renderer* pRenderer);
    void load_texture(const std::string& sKey, const std::string& sSpritesheetKey, SDL_Rect clip);

    SDL_Texture* get_spritesheet(const std::string& sKey) const;
    Texture get_texture(const std::string& sKey) const;

    ~TextureManager();
};

}

#endif // TEXTURE_MANAGER_H
