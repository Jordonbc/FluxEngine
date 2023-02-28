#pragma once
#include "../Flux.h"

#ifdef FLUX_PLATFORM_WINDOWS

extern Flux::Application* Flux::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Flux::CreateApplication();
    app->Run();
    delete app;
}
#endif