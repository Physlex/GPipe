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
     * @details Defines a rotation matrix via scalars
     */
     Rotation(GLfloat _thetaX, GLfloat _thetaY, GLfloat _thetaZ);

     /**
     * Mutator,
     * @details Updates the current rotation theta by some input
     * @param newX, new thetaX
     * @param newY, new thetaY
     * @param newZ, new thetaZ
     */
     void UpdateRotation(GLfloat newX, GLfloat newY, GLfloat newZ);

     /**
     * Extractor,
     * @details returns the current rotation matrix
     * @return rotMatrix
     */
     mat4 GetRotationMatrix();
   private:
     GLfloat thetaX;
     GLfloat thetaY;
     GLfloat thetaZ;
     mat4 rotMatrix;
   };
 }

#endif
