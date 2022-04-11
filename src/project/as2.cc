#include "Transform.h"
#include "Init.h"
#include <Angel.h>
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

//Globals

static const std::string name = "Spinning Square";
#define METHOD GL_TRIANGLE_FAN
#define SQUARESIZE 4
#define NUMOBJECTS 6
#define WIN_SIZE 524
#define DIM 3

//Currently Rendered object's vertex data

vec4 cubeFaces[NUMOBJECTS][SQUARESIZE] = {
  {
    vec4(-0.5, -0.5, -0.5, 1.0),
    vec4(-0.5, 0.5, -0.5, 1.0),
    vec4(0.5, 0.5, -0.5, 1.0),
    vec4(0.5, -0.5, -0.5, 1.0),
  },
  {
    vec4(0.25, -0.25, 0.5, 1.0),
    vec4(-0.25, -0.25, 0.5, 1.0),
    vec4(-0.25, 0.25, 0.5, 1.0),
    vec4(0.25, 0.25, 0.5, 1.0),
  },
  {
    vec4(-0.25, -0.25, 0.5, 1.0),
    vec4(-0.5, -0.5, -0.5, 1.0),
    vec4(-0.5, 0.5, -0.5, 1.0),
    vec4(-0.25, 0.25, 0.5, 1.0),
  },
  {
    vec4(0.25, 0.25, 0.5, 1.0),
    vec4(0.5, 0.5, -0.5, 1.0),
    vec4(0.5, -0.5, -0.5, 1.0),
    vec4(0.25, -0.25, 0.5, 1.0),
  },
  {
    vec4(0.25, -0.25, 0.5, 1.0),
    vec4(0.5, -0.5, -0.5, 1.0),
    vec4(-0.5, -0.5, -0.5, 1.0),
    vec4(-0.25, -0.25, 0.5, 1.0),
  },
  {
    vec4(-0.25, 0.25, 0.5, 1.0),
    vec4(-0.5, 0.5, -0.5, 1.0),
    vec4(0.5, 0.5, -0.5, 1.0),
    vec4(0.25, 0.25, 0.5, 1.0),
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

double conversion =  M_PI/180;
double radians = 0.2;
double degreeConverted = radians / conversion;

Al::Rotation crotation(degreeConverted, 0.0, 0.0);
Al::Translation ctranslation(0.0, -1.0, 0.0);

enum CameraState { PERSPECTIVE, PARALLEL };
CameraState currCamState = PARALLEL;
GLuint modelViewLoc; GLuint projLoc;
mat4 proj;

//Prototypes

void KeyPress(unsigned char key, int x, int y);
void SpecialKeyPress(int key, int x, int y);

void SwapBuffer(GLuint vaoID, GLuint buffID);
void DisplayWindow(void);

void MouseFunction(int button, int state, int x, int y);

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
    glVertexAttribPointer(attribID1, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    attribID2 = glGetAttribLocation(progID, vInput.c_str());
    glEnableVertexAttribArray(attribID2);
    glVertexAttribPointer(attribID2, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
  }

  glutDisplayFunc(DisplayWindow);
  glutKeyboardFunc(KeyPress);
  glutSpecialFunc(SpecialKeyPress);
  glutMouseFunc(MouseFunction);
  glutMainLoop();
  return 0;
}

mat4 GetProjection(mat4 modelView) {
  GLfloat z1 = 1e10;
  GLfloat z2 = -1e10;

  for (int i = 0; i < NUMOBJECTS; i++) {
    for (int j = 0; j < SQUARESIZE; j++) {
      auto p = modelView * cubeFaces[i][j];
      z1 = std::min(z1, -p.z);
      z2 = std::max(z2, -p.z);
    }
  }
  GLfloat _near;
  GLfloat _far;

  if (currCamState == PERSPECTIVE) {
    _near = z1 - 0.01;
    _far = z2 + 0.01;
    return Perspective(90, 1.0, _near, _far);
  } else if (currCamState == PARALLEL) {
    _near = z1;
    _far = z2 + 0.5;
    return Ortho(-1.0, 1.0, -1.0, 1.0, _near, _far + 100);
  }
  return 0;
}

/**
* Fundtion for what is displayed in the window
**/
void DisplayWindow(void) {
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClearDepth(1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  mat4 model = frustrum.GetTransform();
  vec4 eye(0.0, -1.0 - ctranslation.Y(), 0.0, 1.0);
  vec4 at(0.0, 0.0, 0.0, 1.0);
  vec4 up(0.0, 0.0, 1.0, 0.0);
  mat4 view = LookAt(eye, at, up) * crotation.GetRotationMatrix();
  mat4 modelview = view * model;

  proj = GetProjection(modelview);

  glUniformMatrix4fv(modelViewLoc, 1, GL_TRUE, modelview);
  glUniformMatrix4fv(projLoc, 1, GL_TRUE, proj);

  for (int i = 0; i < NUMOBJECTS; i++) {
    glUniform1i(colourLoc, i);
    glBindVertexArray(vaoBufferID[i]);
    glDrawArrays(METHOD, 0, 4);
  }

  glutSwapBuffers();
}


/**
* Functions used to manipulate the model matrix
**/
void PressScaleUp() {
  fscale *= 1.05;
}

void PressScaleDown() {
  fscale /= 1.05;
}

void PressRotateX() {
  frotation.UpdateRotationX(frotation.X() + 1);
}

void PressRotateY() {
  frotation.UpdateRotationY(frotation.Y() + 1);
}

void PressRotateZ() {
  frotation.UpdateRotationZ(frotation.Z() + 1);
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

/**
* Methods to manipulate the camera
**/
void PressPerspectiveSwap() {
  switch (currCamState) {
    case PERSPECTIVE:
    currCamState = PARALLEL;
    break;
    case PARALLEL:
    currCamState = PERSPECTIVE;
    break;
    default:
    currCamState == PERSPECTIVE;
    break;
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

/**
* Key bindings
**/
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

/**
* More camera bindings
**/
void RotateCamPosXY() {
  crotation.UpdateRotationZ(crotation.Z() + degreeConverted);
}

void RotateCamNegXY() {
  crotation.UpdateRotationZ(crotation.Z() - degreeConverted);
}

void MWZoomIn() {
  GLfloat prevY = ctranslation.Y();
  ctranslation.UpdateTranslationY(ctranslation.Y() - 0.1);
  GLfloat newY = ctranslation.Y();
  if (newY < 1.0) {
    ctranslation.UpdateTranslationY(prevY);
  }
}

void MWZoomOut() {
  GLfloat prevY = ctranslation.Y();
  ctranslation.UpdateTranslationY(ctranslation.Y() + 0.1);
  GLfloat newY = ctranslation.Y();
}

/**
* Mouse 
**/
void MouseFunction(int button, int state, int x, int y) {
  switch (button) {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN) {
        RotateCamPosXY();
      }
    break;
    case GLUT_RIGHT_BUTTON:
      if (state == GLUT_DOWN) {
        RotateCamNegXY();
      }
    break;
  }

  if (button == 3) {
    MWZoomIn();
  } else if (button == 4) {
    MWZoomOut();
  }

  glutPostRedisplay();
  frustrum.UpdateAll(frotation, ftranslation, fscale);
}
