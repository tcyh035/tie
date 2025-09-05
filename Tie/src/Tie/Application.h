#pragma once

#include "Core.h"

namespace Tie {
class TIE_API Application {
 public:
  Application();
  virtual ~Application();
  virtual void Run();
};
}  // namespace Tie