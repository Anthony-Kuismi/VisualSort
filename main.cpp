#include <memory>
#include "GUI.h"

int main(int, char**){
  std::unique_ptr<GUI> gui = std::make_unique<GUI>();
  gui->setBackgroundColor( 0.0f, 0.4f, 0.6f );
  gui->mainLoop();
  exit(EXIT_SUCCESS);
}
