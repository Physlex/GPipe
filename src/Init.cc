#include <Angel.h>
#include "../include/Alex/Init.h"

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
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitContextVersion(3, 2);
  glutInitContextProfile(GLUT_CORE_PROFILE);
}

void Init::InitWindow() {
  glutInitWindowSize(x, y);
  glutCreateWindow(windowName);
  glewInit();
}
