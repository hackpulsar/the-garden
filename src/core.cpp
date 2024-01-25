#include "core.h"

#include <string>

#include "log.h"
#include "definitions.hpp"
#include "ticks_management.hpp"

namespace Core
{

Core::Core()
    : m_pRenderer(nullptr), m_pWindow(nullptr), m_bRunning(false), m_pGameData(std::make_shared<GameData>())
{ }

Core::~Core()
{
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}

bool Core::Init()
{
    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        LOG(LogType::Error, std::string("Video initialization error: " + std::string(SDL_GetError())).c_str());
        return false;
    }

    // Init SDL_Window
    m_pWindow = SDL_CreateWindow(
        APP_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN 

    );
    if (m_pWindow == NULL)
    {
        LOG(LogType::Error, std::string("Window initialization error: " + std::string(SDL_GetError())).c_str());
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    if (m_pWindow == NULL)
    {
        LOG(LogType::Error, std::string("Renderer initialization error: " + std::string(SDL_GetError())).c_str());
        return false;
    }

    m_pGameData->m_TileMap = new TileMap();
    m_pGameData->m_TextureManager = new TextureManager();

    // Loading all textures
    m_pGameData->m_TextureManager->load_spritesheet("tiles", "../res/tiles_spritesheet.png", m_pRenderer);
    m_pGameData->m_TextureManager->load_texture("dirt", "tiles", { 0, 0, 16, 16 });

    m_pGameData->m_TileMap->Init(*m_pGameData->m_TextureManager);

    return true;
}

void Core::Run()
{
    m_bRunning = true;
    int next_time;

    while (m_bRunning)
    {
        next_time = SDL_GetTicks() + TICKS_INTERVAL;

        HandleInput();
        Update();

        SDL_Delay(GetTicks(next_time));
        next_time += TICKS_INTERVAL;

        Render();
    }
}

void Core::HandleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            m_bRunning = false;
            break;
        }
    }
}

void Core::Update()
{
}

void Core::Render()
{
    SDL_SetRenderDrawColor(m_pRenderer, 30, 30, 30, 255);
    SDL_RenderClear(m_pRenderer);

    m_pGameData->m_TileMap->Render(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}

}
