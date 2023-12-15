#include "core.h"

int main()
{
    Core::Core core;

    if (core.Init())
        core.Run();
    else
        return -1;

    return 0;
}

