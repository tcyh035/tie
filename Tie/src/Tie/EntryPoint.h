#pragma once

#ifdef TIE_PLATFORM_WINDOWS

extern Tie::Application* Tie::CreateApplication();

int main(int argc, char** argv)
{
    Tie::Log::Init();
    TIE_CORE_TRACE("Initialized log!");
    int a = 5;
    TIE_INFO("Hello! a is {0}", a);

    auto app = Tie::CreateApplication();
    app->Run();
    delete app;
}
#endif