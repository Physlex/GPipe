#include "../include/Alex/Pipe.h"

//Global


//Must be defined in vShader


static const GLint DIM = 3;

//Constructors

Pipe::Pipe()
  : vaoID(0), buffID(0) {
    vaoID = 0;
    buffID = 0;
}

//Public fields

void Pipe::DrawScheme() {
  // for (int i = 0; i < NUMOBJECTS; i++) {
  //   Buffer tempBuff(i, i);
  //   bufferVec.push_back(tempBuff);
  // }

  // InitializeShaders();
  // DefineAttribute(vColour.c_str());
  // DefineAttribute(vInput.c_str());
}

void Pipe::InitializeShaders() {

}

//Private fields

void Pipe::CreateBuffer(int bufferAt, GLuint numObjects, GLsizeiptr size, const void *data) {
  // bufferVec[bufferAt].DefineVAO(numObjects);
  // bufferVec[bufferAt].DefineAO(numObjects, GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void Pipe::DefineAttribute(const char *inName, GLint buffLoc) {
}

//Get/Set methods

GLuint Pipe::GetProgramID() {
  return progID;
}

std::vector<Buffer> Pipe::GetBufferObject() {
  return bufferVec;
}

GLuint Pipe::GetVaoID() {
  return vaoID;
}

GLuint Pipe::GetBuffID() {
  return buffID;
}

//Operator overloading

Pipe Pipe::operator=(Pipe RHS) {
  bufferVec = RHS.GetBufferObject();
  progID = RHS.GetProgramID();
  vaoID = RHS.GetVaoID();
  buffID = RHS.GetBuffID();
  return *this;
}
