#ifndef BUFF_H
#define BUFF_H

#include <Angel.h>

class Buffer
{
 public:
   /**
   *  Creates ID for opengl memory
   *  @param vaoID, sets arrayBufferID
   *  @param buffID, sets vaoBufferID
   */
   Buffer(GLuint vaoID, GLuint buffID);

   /**
   *  Defines the vertex array object buffer
   */
   void DefineVAO(GLuint numObjects);

   /**
   *  Defines the Array object holding vertex positions
   */
   void DefineAO(
     GLuint numObjects,
     GLenum target,
     GLsizeiptr size,
     const void * data,
     GLenum usage);
 private:
   GLuint vaoBufferID; GLuint arrayBufferID;
};

#endif
