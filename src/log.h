#ifndef LOG_HPP
#define LOG_HPP

namespace Core
{

enum class LogType { Info = 0, Warning, Error };

void LOG(const LogType logType, const char* sMessage);

}

#endif // LOG_HPP
