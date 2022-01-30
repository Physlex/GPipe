#include "../include/Alex/Pipe.h"

//Global

static const std::string fshader = "shaders/fshader.glsl";
static const std::string vshader = "shaders/vshader.glsl";
static const std::string vInput = "vPosition";
static const std::string vUniform = "uTheta";


//Constructors

Pipe::Pipe(Buffer *_genBuffer, GLint _thetaLoc)
  : genBuffer(_genBuffer), vaoID(0), buffID(0), thetaLoc(_thetaLoc) {
    genBuffer = _genBuffer;
    vaoID = 0; buffID = 0;
    thetaLoc = _thetaLoc;
}

//Public fields

void Pipe::DrawScheme() {
  vec2 vertexData[MAXPOINTS];
  for (int i = 0; i < MAXPOINTS;   )
  CreateBuffer(1, sizeof(vertexData), vertexData);
  InitializeShaders();
}

void Pipe::CreateBuffer(GLuint numObjects, GLsizeiptr size, const void *data) {
  Buffer genBuffer(vaoID, buffID);
  genBuffer.DefineVAO(numObjects);
  genBuffer.DefineAO(numObjects, GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Pipe::InitializeShaders() {
  GLuint program = InitShader(vshader.c_str(), fshader.c_str());
  glUseProgram(program);
  DefineAttribute(program, vInput.c_str());
  DefineUniform(program, vUniform.c_str());
  glClearColor(0.0, 0.0, 0.0, 1.0);
}

//Private fields

void Pipe::DefineAttribute(GLuint progID, const char *inName) {
  GLuint attribID = glGetAttribLocation(progID, inName);
  glEnableVertexAttribArray(attribID);
  glVertexAttribPointer(attribID, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
}

void Pipe::DefineUniform(GLuint progID, const char *inName) {
  thetaLoc = glGetUniformLocation(progID, inName);
}
