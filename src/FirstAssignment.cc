#include <string>
#include "../include/Alex/Pipe.h"

//Globals

#define WIN_SIZE 524
#define METHOD GL_TRIANGLE_FAN

//Vertex Obj
//Manipulators

GLfloat theta = 0.0;
GLint thetaLoc;

//Names

static const std::string name = "Spinning Square";

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void DisplayWindow(void);

void Idle();

//Main

int main( int argc, char **argv ) {
  Init program(name.c_str(), WIN_SIZE);
  program.StartInitialization(argc, argv);

  Buffer pipeBuffer(0, 0);
  Object pipeObject(CUBE);
  Pipe pipeline(&pipeBuffer, &pipeObject, thetaLoc);
  pipeline.DrawScheme();

  glutDisplayFunc(DisplayWindow);
  glutKeyboardFunc(KeyPress);

  glutMainLoop();
  return 0;
}

void DisplayWindow(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glUniform1f(thetaLoc, theta);
  glDrawArrays(METHOD, 0, MAXPOINTS);
  glutSwapBuffers();
}

void Idle() {
  theta += 0.01;
  glutPostRedisplay();
}

void KeyPress(unsigned char key, int x, int y) {
  switch (key) {
  case 033:
    exit(EXIT_SUCCESS);
    break;
  case 'e':
    glutIdleFunc(0);
    break;
  case 's':
    glutIdleFunc(Idle);
    break;
  }
}
