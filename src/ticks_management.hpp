#ifndef TICKS_MANAGEMENT_HPP
#define TICKS_MANAGEMENT_HPP

#include <SDL_timer.h>

#define TICKS_INTERVAL 60 // NOTE: that's not FPS, it's the interval between ticks in ms

Uint32 GetTicks(const Uint32 next_time)
{
    Uint32 now = SDL_GetTicks();
    if(next_time <= now)
        return 0;
    else
        return next_time - now;
}

#endif // TICKS_MANAGEMENT_HPP
