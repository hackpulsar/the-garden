#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <SDL2/SDL_render.h>

namespace Core
{

struct Texture
{
    SDL_Texture* m_pSpriteSheet;
    SDL_Rect m_ClipRect;
};

}

#endif // TEXTURE_HPP
