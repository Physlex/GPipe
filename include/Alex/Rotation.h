#ifndef ROTATION_H
#define ROTATION_H

#include <Angel.h>
namespace Al {
  /**
  * @class Rotation Rotation.h "Rotation.h"
  * @details converts scalar GLFloats to a rotation matrix
  */
  class Rotation {
   public:
     /**
     * Constructor,
     * Defines a rotation matrix via scalars
     */
     Rotation(GLfloat _thetaX, GLfloat _thetaY, GLfloat _thetaZ);
   private:
     GLfloat thetaX;
     GLfloat thetaY;
     GLfloat thetaZ;
     mat4 rotMatrix;
   };
 }

#endif
