#pragma once

#include <memory>


#include "Core.h"
#include "spdlog/spdlog.h"

namespace Flux
{
    class FLUX_API Log
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

// Core log macros
#define FLUX_CORE_TRACE(...) ::Flux::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLUX_CORE_INFO(...) ::Flux::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLUX_CORE_WARN(...) ::Flux::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLUX_CORE_ERROR(...) ::Flux::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLUX_CORE_FATAL(...) ::Flux::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define FLUX_TRACE(...) ::Flux::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FLUX_INFO(...) ::Flux::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FLUX_WARN(...) ::Flux::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FLUX_ERROR(...) ::Flux::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FLUX_FATAL(...) ::Flux::Log::GetCoreLogger()->fatal(__VA_ARGS__)
