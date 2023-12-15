#include "log.h"

#include <iostream>

namespace Core
{

void LOG(const LogType logType, const char* sMessage)
{
    switch (logType)
    {
    case LogType::Info:
            std::cout << "[i] " << sMessage << std::endl;
        break;
    case LogType::Warning:
        #ifdef __APPLE__
        std::cout << "\x1b[33m[W] " << sMessage << "\x1b[0m" << std::endl;
        #endif

        #ifdef __MINGW32__
        #include <Windows.h>
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
        std::cout << "[W] " << sMessage << std::endl;
        #endif

        #ifdef __linux__
        std::cout << "\033[33m [W] " << sMessage << "\033[0m" << std::endl;
        #endif
        break;
    case LogType::Error:
        #ifdef __APPLE__
        std::cout << "\x1b[31m[E] " << sMessage << "\x1b[0m" << std::endl;
        #endif

        #ifdef __MINGW32__
        #include <Windows.h>
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        std::cout << "[E] " << sMessage << std::endl;
        #endif

        #ifdef __linux__
        std::cout << "\033[31m[E] " << sMessage << "\033[0m" << std::endl;
        #endif
        break;
    }

}

}
