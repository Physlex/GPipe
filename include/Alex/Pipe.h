#ifndef PIPE_H
#define PIPE_H

/**
* Includes for use in PIPE framework
*/
///////////////////
#include "Init.h"
#include "Buffer.h"
///////////////////
#include <Angel.h> //Extended from Angel
///////////////////

static const GLuint MAXPOINTS = 32;

class Pipe
{
 public:
   /**
   *  Pass instantiated buffer object
   */
   Pipe(Buffer *_genBuffer, GLint _thetaLoc);

   /**
   *  Creates a vertex object for use in CreateBuffer and InitShader
   *  @details Programmer builds algorithim here.
   *  Meant to be more expandable then the main file.
   */
   void DrawScheme();

 private:
   /**
   *  Creates buffer relevant to current scheme
   */
   void CreateBuffer(GLuint numObjects, GLsizeiptr size, const void *data);

   /**
   *  Initializes shader and attrib data
   */
   void InitializeShaders();

   /**
   *  Defines vertex attributes in shader
   *  @param progID, generated by glUseProgram
   *  @param inName, filename where vshader is defined
   */
   void DefineAttribute(GLuint progID, const char *inName);

   /**
   *  DefineUniform vars in shader
   *  @param progID, generated by glUseProgram
   *  @param inName, filename where fshader is defined
   */
   void DefineUniform(GLuint progID, const char *inName);

   Buffer *genBuffer;
   GLuint vaoID; GLuint buffID;
   GLint thetaLoc;
};

#endif