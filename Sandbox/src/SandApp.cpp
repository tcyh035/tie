#include <Tie.h>

#include <iostream>

class SandBox : public Tie::Application {
 public:
  SandBox() {}
  ~SandBox() {

  };

  void Run() override { std::cout << "Hello 111" << std::endl; }
};

int main() {
  Tie::Application* sandbox = new SandBox();
  sandbox->Run();
  delete sandbox;
}