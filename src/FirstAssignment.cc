#include <string>
#include "../include/Alex/Pipe.h"

//Globals

#define WIN_SIZE 524

//Manipulators

//Is this right?

GLfloat theta_x = 0.0; GLfloat theta_y = 0.0; GLfloat theta_z = 0.0;
GLfloat pos_x = 0.0; GLfloat pos_y = 0.0; GLfloat pos_z = 0.0;
GLfloat scale = 1.00;
GLuint modelViewLoc; GLuint projLoc; GLuint colourLoc;

//Names

static const std::string name = "Spinning Square";

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void SpecialKeyPress(int key, int x, int y);
void DisplayWindow(void);

//Main

int main(int argc, char **argv) {
  Init program(name.c_str(), WIN_SIZE);
  program.StartInitialization(argc, argv);

  Buffer pipeBuffer;
  Pipe pipeline(pipeBuffer);
  pipeline.InitializeShaders();
  pipeline.DrawScheme();

  modelViewLoc = glGetUniformLocation(pipeline.GetProgramID(), "uModelView");
  projLoc = glGetUniformLocation(pipeline.GetProgramID(), "uProjection");

  glutDisplayFunc(DisplayWindow);
  glutKeyboardFunc(KeyPress);
  glutSpecialFunc(SpecialKeyPress);

  glutMainLoop();
  return 0;
}

void DisplayWindow(void) {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  mat4 model = Translate(pos_x, pos_y, pos_z) * RotateX(theta_x) * RotateY(theta_y) * RotateZ(theta_z) * Scale(scale, scale, scale);
  vec4 eye(0.0, -1.0, -1.0, 1.0);
  vec4 at(0.0, 0.0, 0.0, 1.0);
  vec4 up(0.0, 0.0, 1.0, 0.0);
  mat4 view = LookAt(eye, at, up);
  mat4 modelview = view * model;
  glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, modelview);

  mat4 proj = Ortho(-1, 1, -1, 1, -1, 100);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, proj);

  for (int i = 0; i < 2; i++) { //2 for now, it will be changed later
    glDrawArrays(METHOD, 0, SQUARESIZE);
  }

  glutSwapBuffers();
}

void PressScaleUp() {
  scale = scale * 1.05;
  glutPostRedisplay();
}

void PressScaleDown() {
  scale = scale / 1.05;
  glutPostRedisplay();
}

void PressRotateX() {
  theta_x += 0.5;
  glutPostRedisplay();
}

void PressRotateY() {
  theta_y += 0.5;
  glutPostRedisplay();
}

void PressRotateZ() {
  theta_z += 0.5;
  glutPostRedisplay();
}

void PressTranslateRight() {
  pos_x += 0.05;
  glutPostRedisplay();
}

void PressTranslateLeft() {
  pos_x -= 0.05;
  glutPostRedisplay();
}

void PressTranslateUp() {
  pos_z += 0.05;
  glutPostRedisplay();
}

void PressTranslateDown() {
  pos_z -= 0.05;
  glutPostRedisplay();
}

void KeyPress(unsigned char key, int x, int y) {
  switch (key) {
  case 033:
    exit(EXIT_SUCCESS);
    break;
  }
}

void SpecialKeyPress(int key, int x, int y) {
  switch (key) {
  case GLUT_KEY_RIGHT:
    PressTranslateRight();
    break;
  case GLUT_KEY_LEFT:
    PressTranslateLeft();
    break;
  case GLUT_KEY_DOWN:
    PressTranslateDown();
    break;
  case GLUT_KEY_UP:
    PressTranslateUp();
    break;
  case GLUT_KEY_PAGE_UP:
    PressScaleUp();
    break;
  case GLUT_KEY_PAGE_DOWN:
    PressScaleDown();
    break;
  case GLUT_KEY_HOME:
    PressRotateX();
    break;
  case GLUT_KEY_END:
    PressRotateY();
    break;
  case GLUT_KEY_INSERT:
    PressRotateZ();
    break;
  }
}
