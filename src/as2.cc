#include <string>
#include "Transform.h"
#include "Init.h"
#include <Angel.h>

//Globals

static const std::string name = "Spinning Square";
#define METHOD GL_TRIANGLE_FAN
#define SQUARESIZE 4
#define NUMOBJECTS 6
#define WIN_SIZE 524
#define DIM 3

//Currently Rendered object's vertex data

vec3 cubeFaces[NUMOBJECTS][SQUARESIZE] = {
  {
    vec3(-0.5, -0.5, -0.5),
    vec3(-0.5, 0.5, -0.5),
    vec3(0.5, 0.5, -0.5),
    vec3(0.5, -0.5, -0.5),
  },
  {
    vec3(0.25, -0.25, 0.5),
    vec3(-0.25, -0.25, 0.5),
    vec3(-0.25, 0.25, 0.5),
    vec3(0.25, 0.25, 0.5),
  },
  {
    vec3(-0.25, -0.25, 0.5),
    vec3(-0.5, -0.5, -0.5),
    vec3(-0.5, 0.5, -0.5),
    vec3(-0.25, 0.25, 0.5),
  },
  {
    vec3(0.25, 0.25, 0.5),
    vec3(0.5, 0.5, -0.5),
    vec3(0.5, -0.5, -0.5),
    vec3(0.25, -0.25, 0.5),
  },
  {
    vec3(0.25, -0.25, 0.5),
    vec3(0.5, -0.5, -0.5),
    vec3(-0.5, -0.5, -0.5),
    vec3(-0.25, -0.25, 0.5),
  },
  {
    vec3(-0.25, 0.25, 0.5),
    vec3(-0.5, 0.5, -0.5),
    vec3(0.5, 0.5, -0.5),
    vec3(0.25, 0.25, 0.5),
  },
};

GLuint objectBufferID[NUMOBJECTS];
GLuint vaoBufferID[NUMOBJECTS];

//Object Data

Al::Rotation frotation(0.0, 0.0, 0.0);
Al::Translation ftranslation(0.0, 0.0, 0.0);
Al::Scale fscale(1.0, 1.0, 1.0);
Al::Transform frustrum(frotation, ftranslation, fscale);

//Shader Data

static const std::string fshader = "shaders/fshader.glsl";
static const std::string vshader = "shaders/vshader.glsl";
static const std::string vInput = "vPosition";
static const std::string vColour = "vColour";
GLuint attribID1;
GLuint attribID2;
GLuint colourLoc;

//Camera/Viewer Data

enum CameraState { PERSPECTIVE, PARALLEL };
CameraState currCamState = PARALLEL;
GLuint modelViewLoc; GLuint projLoc;
mat4 proj;

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void SpecialKeyPress(int key, int x, int y);

void SwapBuffer(GLuint vaoID, GLuint buffID);
void DisplayWindow(void);

//Main

int main(int argc, char **argv) {
  Init program(name.c_str(), WIN_SIZE);
  program.StartInitialization(argc, argv);

  GLuint progID = InitShader(vshader.c_str(), fshader.c_str());
  glUseProgram(progID);

  modelViewLoc = glGetUniformLocation(progID, "uModelView");
  projLoc = glGetUniformLocation(progID, "uProjection");
  colourLoc = glGetUniformLocation(progID, "uColourIndex");

  glGenVertexArrays(NUMOBJECTS, vaoBufferID);
  glGenBuffers(NUMOBJECTS, objectBufferID);

  for (int i = 0; i < NUMOBJECTS; i++) {
    glBindVertexArray(vaoBufferID[i]);
    glBindBuffer(GL_ARRAY_BUFFER, objectBufferID[i]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeFaces[i]), cubeFaces[i], GL_STATIC_DRAW);

    attribID1 = glGetAttribLocation(progID, vColour.c_str());
    glEnableVertexAttribArray(attribID1);
    glVertexAttribPointer(attribID1, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    attribID2 = glGetAttribLocation(progID, vInput.c_str());
    glEnableVertexAttribArray(attribID2);
    glVertexAttribPointer(attribID2, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  }

  glutDisplayFunc(DisplayWindow);
  glutKeyboardFunc(KeyPress);
  glutSpecialFunc(SpecialKeyPress);

  glutMainLoop();
  return 0;
}

void DisplayWindow(void) {
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  mat4 model = frustrum.GetTransform();
  vec4 eye(0.0, -1.0, 0.0, 1.0);
  vec4 at(0.0, 0.0, 0.0, 1.0);
  vec4 up(0.0, 0.0, 1.0, 0.0);
  mat4 view = LookAt(eye, at, up);
  mat4 modelview = view * model;

  if (currCamState == PERSPECTIVE) {
    proj = Perspective(90, 1, -1, 100);
  } else if (currCamState == PARALLEL) {
    proj = Ortho(-1, 1, -1, 1, -1, 100);
  }

  glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, modelview);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, proj);

  for (int i = 0; i < NUMOBJECTS; i++) {
    glUniform1i(colourLoc, i);
    glBindVertexArray(vaoBufferID[i]);
    glDrawArrays(METHOD, 0, 4);
  }

  glutSwapBuffers();
}

void PressScaleUp() {
  fscale *= 1.05;
}

void PressScaleDown() {
  fscale /= 1.05;
}

void PressRotateX() {
  frotation.UpdateRotationX(frotation.X() + 0.5);
}

void PressRotateY() {
  frotation.UpdateRotationY(frotation.Y() + 0.5);
}

void PressRotateZ() {
  frotation.UpdateRotationZ(frotation.Z() + 0.5);
}

void PressTranslateRight() {
  ftranslation.UpdateTranslationX(ftranslation.X() + 0.05);
}

void PressTranslateLeft() {
  ftranslation.UpdateTranslationX(ftranslation.X() - 0.05);
}

void PressTranslateUp() {
  ftranslation.UpdateTranslationY(ftranslation.Y() + 0.05);
}

void PressTranslateDown() {
  ftranslation.UpdateTranslationY(ftranslation.Y() - 0.05);
}

void PressPerspectiveSwap() {
  if (currCamState == PERSPECTIVE) {
    currCamState == PARALLEL;
  } else if (currCamState == PARALLEL) {
    currCamState == PERSPECTIVE;
  }
}

void KeyPress(unsigned char key, int x, int y) {
  switch (key) {
  case 'p':
    PressPerspectiveSwap();
    break;
  case 033:
    exit(EXIT_SUCCESS);
    break;
  }

  glutPostRedisplay();
  frustrum.UpdateAll(frotation, ftranslation, fscale);
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

  glutPostRedisplay();
  frustrum.UpdateAll(frotation, ftranslation, fscale);
}
