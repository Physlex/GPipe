#include <Angel.h>
#include "Init.h"

//Constructors

Init::Init(const char *_windowName, int s)
  : x(s), y(s), windowName(_windowName) {
  x = s;
  y = s;
  windowName = _windowName;
}

Init::Init(const char *_windowName, int m, int n)
  : x(m), y(n), windowName(_windowName) {
  x = m;
  y = n;
  windowName = _windowName;
}

//Public fields

void Init::StartInitialization(int argc, char **argv) {
  InitGlewGlut(argc, argv);
  InitWindow();
}

//Private fields

void Init::InitGlewGlut(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitContextVersion(3, 2);
  glutInitContextProfile(GLUT_CORE_PROFILE);
}

void Init::InitWindow() {
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
  glutInitWindowSize(x, y);
  glutCreateWindow(windowName);
  glewInit();
}
