#include <string>
#include "../include/Alex/Pipe.h"

//Globals

#define WIN_SIZE 524
#define METHOD GL_TRIANGLE_FAN

//Vertex Obj
//Manipulators

//Is this right?

GLfloat theta_x = 0.0; GLfloat theta_y = 0.0; GLfloat theta_z = 0.0;
GLint thetaLoc;
GLfloat pos_x = 0.0; GLfloat pos_y = 0.0; GLfloat pos_z = 0.0;
GLfloat posLoc;
GLfloat scale = 1.05;
GLfloat scaleLoc;
mat4 model;

GLuint modelViewLoc; GLuint projLoc; GLuint colourLoc;

//Names

static const std::string name = "Spinning Square";

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void DisplayWindow(void);

//Main

int main(int argc, char **argv) {
  Init program(name.c_str(), WIN_SIZE);
  program.StartInitialization(argc, argv);

  Buffer pipeBuffer(0, 0);
  Pipe pipeline(&pipeBuffer, thetaLoc);

  //Is this right?
  modelViewLoc = glGetUniformLocation(pipeline.GetProgramID(), "uModelView");
  projLoc = glGetUniformLocation(pipeline.GetProgramID(), "uProjection");

  //How do I draw multiple objects?
  pipeline.DrawScheme();

  glutDisplayFunc(DisplayWindow);
  glutKeyboardFunc(KeyPress);

  glutMainLoop();
  return 0;
}

void DisplayWindow(void) {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //Ask about this, mainly: How? (They collapse on themselves when drawn)
  //Is this right?
  //Why wont the camera work?
  //model, how exactly do I do this via the api.
  vec4 eye(0.0, -1.0, -1.0, 1.0);
  vec4 at(0.0, 0.0, 0.0, 1.0);
  vec4 up(0.0, 0.0, 1.0, 0.0);
  mat4 view = LookAt(eye, at, up);
  mat4 modelview = view * model;
  glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, modelview);

  //What even is this?
  mat4 proj = Ortho(-1, 1, -1, 1, -1, 100);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, proj);

  glDrawArrays(METHOD, 0, MAXPOINTS);
  glutSwapBuffers();

  glFlush(); //Do I need this after swap buffers?
}

//Have I set this up correctly?

void PressScaleUp() {
  if (scale != 1.05) { scale = 1.05; }
  model *= scale;
  glutPostRedisplay();
}

void PressScaleDown() {
  if (scale != 1.05) { scale = 1.05; }
  model *= 1/scale ;
  glutPostRedisplay();
}

void PressRotateX() {
  theta_x += 0.05;
  glutPostRedisplay();
}

void PressRotateY() {
  theta_y += 0.05;
  glutPostRedisplay();
}

void PressRotateZ() {
  theta_z += 0.05;
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
