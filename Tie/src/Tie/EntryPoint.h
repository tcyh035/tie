#pragma once

#ifdef TIE_PLATFORM_WINDOWS

extern Tie::Application* Tie::CreateApplication();

int main(int argc, char** argv)
{
    Tie::Log::Init();
    TIE_CORE_TRACE("Initialized log!");
    TIE_CLIENT_INFO("Hello!");

    auto app = Tie::CreateApplication();
    app->Run();
    delete app;
}
#endif