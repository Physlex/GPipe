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
     * Methods,
     * @details constructs a new matrix via the operator type
     * @param factor, the factor you scale by
     */
     Rotation operator+(GLfloat factor);
     Rotation operator+=(GLfloat factor);
     Rotation operator-(GLfloat factor);
     Rotation operator-=(GLfloat factor);

     Rotation operator*(GLfloat factor);
     Rotation operator*=(GLfloat factor);
     Rotation operator/(GLfloat factor);
     Rotation operator/=(GLfloat factor);

     /**
     * Mutator,
     * @details Updates the current rotation theta by some input
     * @param newX, new thetaX
     * @param newY, new thetaY
     * @param newZ, new thetaZ
     */
     void UpdateRotation(GLfloat newX, GLfloat newY, GLfloat newZ);

     /**
     * Mutator,
     * @details Updates the x component of rotation
     * @param the newX
     */
     void UpdateRotationX(GLfloat newX);

     /**
     * Mutator,
     * @details Updates the y component of rotation
     * @param the newY
     */
     void UpdateRotationY(GLfloat newY);

     /**
     * Mutator,
     * @details Updates the z component of rotation
     * @param the newZ
     */
     void UpdateRotationZ(GLfloat newZ);

     /**
     * Extractor,
     * @details returns the current rotation matrix
     * @return rotMatrix
     */
     mat4 GetRotationMatrix();

     /**
     * Extractor,
     * @details returns the current value of thetaX
     * @retunr thetaX
     */
     GLfloat X();

     /**
     * Extractor,
     * @details returns the current value of thetaY
     * @retunr thetaY
     */
     GLfloat Y();

     /**
     * Extractor,
     * @details returns the current value of thetaZ
     * @retunr thetaZ
     */
     GLfloat Z();

   private:
     /**
     * Helper,
     * @details updates the rotation matrix with new scalars
     */
     void UpdateMatrix();

     GLfloat thetaX;
     GLfloat thetaY;
     GLfloat thetaZ;
     mat4 rotMatrix;
   };
 }

#endif
