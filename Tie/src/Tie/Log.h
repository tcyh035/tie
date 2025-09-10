#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory>

namespace Tie {
    class TIE_API Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// CORE LOG MACROS
#define TIE_CORE_TRACE(...)     ::Tie::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TIE_CORE_INFO(...)      ::Tie::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TIE_CORE_DEBUG(...)     ::Tie::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define TIE_CORE_WARN(...)      ::Tie::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TIE_CORE_FATAL(...)     ::Tie::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT LOG MACROS
#define TIE_TRAGE(...)   ::Tie::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TIE_INFO(...)    ::Tie::Log::GetClientLogger()->info(__VA_ARGS__)
#define TIE_DEBUG(...)   ::Tie::Log::GetClientLogger()->debug(__VA_ARGS__)
#define TIE_WARN(...)    ::Tie::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TIE_FATAL(...)   ::Tie::Log::GetClientLogger()->critical(__VA_ARGS__)