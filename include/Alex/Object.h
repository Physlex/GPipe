#ifndef OBJECT_H
#define OBJECT_H

#include <map>
#include "objData/Cube.h"

enum GPenum { CUBE };

class Object
{
 public:
   /**
   *  Sets an object target
   */
   Object(GPenum target = CUBE);

   /**
   *  Clean up
   */
   ~Object();

   /**
   *  Gets vec4 target in vertexData
   */
   vec2 *GetTarget();

   /**
   *  Returns a matrix of vectors to create a 3D cube
   */
   vec2 *CreateCubeObj(void);


 private:
   Cube *cubeData;
   vec2 *cubeVertexData;
   GPenum state;
};

#endif
