#ifndef ENGINE_COMMON_H
#define ENGINE_COMMON_H

#include "spdlog/spdlog.h"

namespace Engine {

#define ENGINE_DEBUG

#define ENGINE_GL_MAJOR 3
#define ENGINE_GL_MINOR 3

#ifdef ENGINE_DEBUG
#define LOG_DEBUG_ON
#endif // ENGINE_DEBUG

#ifdef LOG_DEBUG_ON
#define LOG_DEBUG(...) spdlog::get("console")->debug(__VA_ARGS__)
#define LOG_DEBUG_IF(flag, ...) spdlog::get("console")->debug_if(flag, __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#define LOG_DEBUG_IF(flag, ...)
#endif

} /* Engine */

#endif // ENGINE_COMMON_H
