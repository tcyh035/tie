#pragma once

#ifdef TIE_PLATFORM_WINDOWS

extern Tie::Application* Tie::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Tie::CreateApplication();
    app->Run();
    delete app;
}
#endif