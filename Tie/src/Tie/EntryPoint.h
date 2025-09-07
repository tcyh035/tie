#pragma once

#ifdef TIE_PLATFORM_WINDOWS

extern Tie::Application* Tie::CreateApplication();

int main(int argc, char** argv)
{
    Tie::Log::Init();

    auto app = Tie::CreateApplication();
    app->Run();
    delete app;
}
#endif