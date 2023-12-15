#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>

#include "game_data.hpp"

namespace Core
{

class Core {
public:
    Core();
    ~Core();

    bool Init();
    void Run();

    void HandleInput();
    void Update();
    void Render();

private:
    SDL_Renderer* m_pRenderer;
    SDL_Window* m_pWindow;

    bool m_bRunning;

    GameData* m_pGameData;

};

}

#endif // CORE_H
