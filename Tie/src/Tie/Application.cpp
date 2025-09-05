#include "Application.h"

#include <iostream>

namespace Tie {
Application::Application() {}

Application::~Application() {}

void Application::Run() { std::cout << "hello tie engine" << std::endl; }
}  // namespace Tie