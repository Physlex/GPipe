#include "../include/Alex/Pipe.h"

//Global

static const std::string fshader = "shaders/fshader.glsl";
static const std::string vshader = "shaders/vshader.glsl";
//Must be defined in vShader
static const std::string vInput = "vPosition";
static const std::string vColour = "vColour";

static const GLint DIM = 3;

//Constructors

Pipe::Pipe()
  : vaoID(0), buffID(0) {
    vaoID = 0;
    buffID = 0;
}

Pipe::Pipe(Buffer _genBuffer)
  : genBuffer(_genBuffer), vaoID(0), buffID(0) {
    genBuffer = _genBuffer;
    vaoID = 0;
    buffID = 0;
}

//Public fields

void Pipe::DrawScheme() {
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
  // vec3 rightFace[SQUARESIZE] = {
  //   vec3(0.5, 0.5, 0.0),
  //   vec3(-0.5, 0.5, 0.0),
  //   vec3(-0.5, -0.5, 0.0),
  //   vec3(0.5, -0.5, 0.0),
  // };
  // vec3 backFace[SQUARESIZE] = {
  //   vec3(0.5, 0.5, 0.0),
  //   vec3(-0.5, 0.5, 0.0),
  //   vec3(-0.5, -0.5, 0.0),
  //   vec3(0.5, -0.5, 0.0),
  // };
  // vec3 topFace[SQUARESIZE] = {
  //   vec3(0.5, 0.5, 0.0),
  //   vec3(-0.5, 0.5, 0.0),
  //   vec3(-0.5, -0.5, 0.0),
  //   vec3(0.5, -0.5, 0.0),
  // };
  // vec3 botFace[SQUARESIZE] = {
  //   vec3(0.5, 0.5, 0.0),
  //   vec3(-0.5, 0.5, 0.0),
  //   vec3(-0.5, -0.5, 0.0),
  //   vec3(0.5, -0.5, 0.0),
  // };
  vec4 colours[6] = {
    vec4(1.0, 0.0, 0.0, 1.0),
    vec4(0.0, 1.0, 0.0, 1.0),
    vec4(0.0, 0.0, 1.0, 1.0),
    vec4(0.0, 0.0, 0.0, 1.0),
    vec4(1.0, 1.0, 0.0, 1.0),
    vec4(1.0, 1.0, 1.0, 1.0),
  };

  int numObjects = 1;
  CreateBuffer(numObjects, sizeof(frontFace), frontFace);
  DefineAttribute(vColour.c_str());
  DefineAttribute(vInput.c_str());

  CreateBuffer(numObjects, sizeof(leftFace), leftFace);
  DefineAttribute(vColour.c_str());
  DefineAttribute(vInput.c_str());
}

void Pipe::InitializeShaders() {
  progID = InitShader(vshader.c_str(), fshader.c_str());
  glUseProgram(progID);
}

//Private fields

void Pipe::CreateBuffer(GLuint numObjects, GLsizeiptr size, const void *data) {
  genBuffer.DefineVAO(numObjects);
  genBuffer.DefineAO(numObjects, GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Pipe::CreateBuffer(GLuint numObjects, GLsizeiptr sizePoints, GLsizeiptr sizeColours, const void *vertexData, const void *colourData) {
  genBuffer.DefineVAO(numObjects);
  genBuffer.DefineAO(numObjects, GL_ARRAY_BUFFER, sizePoints, sizeColours, vertexData, colourData, GL_STATIC_DRAW);
}

void Pipe::DefineAttribute(const char *inName, GLint buffLoc) {
  GLuint attribID = glGetAttribLocation(progID, inName);
  glEnableVertexAttribArray(attribID);
  glVertexAttribPointer(attribID, DIM, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void Pipe::DefineAttribute(const char *inName, GLsizeiptr sizePoints) {
  GLuint attribID = glGetAttribLocation(progID, inName);
  glEnableVertexAttribArray(attribID);
  glVertexAttribPointer(attribID, DIM, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizePoints));
}

//Get/Set methods

GLuint Pipe::GetProgramID() {
  return progID;
}

Buffer Pipe::GetBufferObject() {
  return genBuffer;
}

GLuint Pipe::GetVaoID() {
  return vaoID;
}

GLuint Pipe::GetBuffID() {
  return buffID;
}

//Operator overloading

Pipe Pipe::operator=(Pipe RHS) {
  genBuffer = RHS.GetBufferObject();
  progID = RHS.GetProgramID();
  vaoID = RHS.GetVaoID();
  buffID = RHS.GetBuffID();
  return *this;
}
