#include <Angel.h>
#include "../include/Alex/Buffer.h"

//Constructors

Buffer::Buffer(GLuint vaoID, GLuint buffID)
  : vaoBufferID(vaoID), arrayBufferID(buffID) {
    vaoBufferID = vaoID;
    arrayBufferID = buffID;
  }

//Public fields

void Buffer::DefineVAO(GLuint numObjects) {
  glGenVertexArrays(numObjects, &vaoBufferID);
  glBindVertexArray(vaoBufferID);
}

void Buffer::DefineAO(GLuint numObjects, GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
    glGenBuffers(numObjects, &arrayBufferID);
    glBindBuffer(target, arrayBufferID);
    glBufferData(target, size, data, usage);
}

void Buffer::DefineAO(GLuint numObjects, GLenum target, GLsizeiptr sizePoints, GLsizeiptr sizeColours, const void * vertexData, const void *colourData, GLenum usage) {
  glGenBuffers(numObjects, &arrayBufferID);
  glBindBuffer(target, arrayBufferID);
  glBufferData(target, sizePoints + sizeColours, NULL, usage);
  DefineSAO(target, sizePoints, sizeColours, vertexData, colourData);
}

void Buffer::DefineSAO(GLenum target, GLsizeiptr sizePoints, GLsizeiptr sizeColours, const void * vertexData, const void *colourData) {
  glBufferSubData(target, 0, sizePoints, vertexData);
  glBufferSubData(target, sizePoints, sizeColours, colourData);
}
