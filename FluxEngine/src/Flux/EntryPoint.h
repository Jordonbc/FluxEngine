#pragma once

#include "Log.h"

#ifdef FLUX_PLATFORM_WINDOWS

extern Flux::Application* Flux::CreateApplication();

int main(int argc, char** argv)
{
    Flux::Log::Init();

    FLUX_CORE_WARN("Logging Initialized!");
    int a = 5;
    FLUX_INFO("Hello! {0}", a);
    
    auto app = Flux::CreateApplication();
    app->Run();
    delete app;
}
#endif