#include <string>
#include <Angel.h>
#include "../include/Alex/Init.h"
//Globals

#define METHOD GL_TRIANGLE_FAN
#define SQUARESIZE 4
#define WIN_SIZE 524
#define DIM 3

vec3 frontFace[SQUARESIZE] = {
  vec3(0.5, 0.5, 0.0),
  vec3(-0.5, 0.5, 0.0),
  vec3(-0.5, -0.5, 0.0),
  vec3(0.5, -0.5, 0.0),
};
vec3 leftFace[SQUARESIZE] = {
  vec3(0.5, 0.5, 1.0),
  vec3(-0.5, 0.5, 1.0),
  vec3(-0.5, -0.5, 1.0),
  vec3(0.5, -0.5, 1.0),
};

GLfloat theta_x = 0.0; GLfloat theta_y = 0.0; GLfloat theta_z = 0.0;
GLfloat pos_x = 0.0; GLfloat pos_y = 0.0; GLfloat pos_z = 0.0;
GLfloat scale = 1.00;
GLuint modelViewLoc; GLuint projLoc; GLuint colourLoc;

GLuint vaoBufferID1 = 0;
GLuint objectBufferID1 = 0;
GLuint vaoBufferID2 = 1;
GLuint objectBufferID2 = 1;
GLuint vaoBufferID3;
GLuint objectBufferID3;
GLuint vaoBufferID4;
GLuint objectBufferID4;
GLuint vaoBufferID5;
GLuint objectBufferID5;
GLuint vaoBufferID6;
GLuint objectBufferID6;

static const std::string fshader = "shaders/fshader.glsl";
static const std::string vshader = "shaders/vshader.glsl";

static const std::string vInput = "vPosition";
static const std::string vColour = "vColour";

//Names

static const std::string name = "Spinning Square";

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void SpecialKeyPress(int key, int x, int y);

void SwapBuffer(GLuint vaoID, GLuint buffID);
void DisplayWindow(void);

//Main

int main(int argc, char **argv) {
  Init program(name.c_str(), WIN_SIZE);
  program.StartInitialization(argc, argv);

  glGenVertexArrays(1, &vaoBufferID1);
  glBindVertexArray(vaoBufferID1);

  glGenBuffers(1, &objectBufferID1);
  glBindBuffer(GL_ARRAY_BUFFER, objectBufferID1);
  glBufferData(GL_ARRAY_BUFFER, sizeof(frontFace), frontFace, GL_STATIC_DRAW);

  glGenVertexArrays(2, &vaoBufferID2);
  glBindVertexArray(vaoBufferID2);

  glGenBuffers(2, &objectBufferID2);
  glBindBuffer(GL_ARRAY_BUFFER, objectBufferID2);
  glBufferData(GL_ARRAY_BUFFER, sizeof(leftFace), leftFace, GL_STATIC_DRAW);

  GLuint progID = InitShader(vshader.c_str(), fshader.c_str());
  glUseProgram(progID);

  modelViewLoc = glGetUniformLocation(progID, "uModelView");
  projLoc = glGetUniformLocation(progID, "uProjection");

  GLuint attribID1 = glGetAttribLocation(progID, vColour.c_str());
  glEnableVertexAttribArray(attribID1);
  glVertexAttribPointer(attribID1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

  GLuint attribID2 = glGetAttribLocation(progID, vInput.c_str());
  glEnableVertexAttribArray(attribID2);
  glVertexAttribPointer(attribID2, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

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

  glBindVertexArray(vaoBufferID1);
  glBindBuffer(GL_ARRAY_BUFFER, objectBufferID1);
  glDrawArrays(METHOD, 0, 4);

  glBindVertexArray(vaoBufferID2);
  glBindBuffer(GL_ARRAY_BUFFER, objectBufferID2);
  glDrawArrays(METHOD, 0, 4);

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
