#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL2/SDL_render.h>
#include <unordered_map>
#include <string>

namespace Core
{

struct TextureManager
{
    std::unordered_map<std::string, SDL_Texture*> m_Textures;

    void load(const std::string& key, const std::string& sPath, SDL_Renderer* pRenderer);
    SDL_Texture* get(const std::string& key) const;

    ~TextureManager();
};

}

#endif // TEXTURE_MANAGER_H
