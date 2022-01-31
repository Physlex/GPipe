#include "../include/Alex/Pipe.h"

//Global

static const std::string fshader = "shaders/fshader.glsl";
static const std::string vshader = "shaders/vshader.glsl";
//Must be defined in vShader
static const std::string vInput = "vPosition";
static const std::string vColour = "vColour";

static const GLint DIM = 3;

//Constructors

Pipe::Pipe(Buffer *_genBuffer, GLint _thetaLoc)
  : genBuffer(_genBuffer), vaoID(0), buffID(0), thetaLoc(_thetaLoc) {
    genBuffer = _genBuffer;
    vaoID = 0; buffID = 0;
    thetaLoc = _thetaLoc;
}

//Public fields

void Pipe::DrawScheme() {
  vec3 points[MAXPOINTS] = {
    vec3(0.5, 0.5, 1.0),
    vec3(-0.5, 0.5, 1.0),
    vec3(-0.5, -0.5, 1.0),
    vec3(0.5, -0.5, 1.0),
  };
  CreateBuffer(1, sizeof(points), points);
  InitializeShaders(sizeof(points));
}

void Pipe::CreateBuffer(GLuint numObjects, GLsizeiptr size, const void *data) {
  Buffer genBuffer(vaoID, buffID);
  genBuffer.DefineVAO(numObjects);
  genBuffer.DefineAO(numObjects, GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Pipe::CreateBuffer(GLuint numObjects, GLsizeiptr sizePoints, GLsizeiptr sizeColours, const void *vertexData, const void *colourData) {
  Buffer genBuffer(vaoID, buffID);
  genBuffer.DefineVAO(numObjects);
  genBuffer.DefineAO(numObjects, GL_ARRAY_BUFFER, sizePoints, sizeColours, vertexData, colourData, GL_STATIC_DRAW);
}

void Pipe::InitializeShaders(GLsizeiptr sizePoints) {
  progID = InitShader(vshader.c_str(), fshader.c_str());
  DefineAttribute(vColour.c_str());
  DefineAttribute(vInput.c_str());
  glUseProgram(progID);
}

//Private fields

void Pipe::DefineAttribute(const char *inName) {
  GLuint attribID = glGetAttribLocation(progID, inName);
  glEnableVertexAttribArray(attribID);
  glVertexAttribPointer(attribID, DIM, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void Pipe::DefineAttribute(const char *inName, GLsizeiptr sizePoints) {
  GLuint attribID = glGetAttribLocation(progID, inName);
  glEnableVertexAttribArray(attribID);
  glVertexAttribPointer(attribID, DIM, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizePoints));
}

void Pipe::DefineUniform(const char *inName) {
  thetaLoc = glGetUniformLocation(progID, inName);
}

//Get/Set methods

GLuint Pipe::GetProgramID() {
  return progID;
}
