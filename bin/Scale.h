#ifndef SCALE_H
#define SCALE_H

#include <Angel.h>
namespace Al {
  /**
  * @class Scale Scale.h "Scale.h"
  * @details creates a scale matrix from scalar components
  */
  class Scale {
  public:
    /**
    *  Constructor,
    *  Creates a scale matrix based on scalar components
    */
    Scale(GLfloat _scaleX, GLfloat _scaleY, GLfloat _scaleZ);

    /**
    * Methods,
    * @details constructs a new matrix via the operator type
    * @param factor, the factor you scale by
    */
    Scale operator-(GLfloat factor);
    Scale operator-=(GLfloat factor);
    Scale operator+(GLfloat factor);
    Scale operator+=(GLfloat factor);

    Scale operator*(GLfloat factor);
    Scale operator*=(GLfloat factor);
    Scale operator/(GLfloat factor);
    Scale operator/=(GLfloat factor);

    /**
    * Mutator,
    * @details updates scalex,y,z with newx,y,z
    * @param newX, the new version of scaleX
    * @param newY, the new version of scaleY
    * @param newZ, the new version of scaleZ
    */
    void UpdateScale(GLfloat newX, GLfloat newY,GLfloat newZ);

    /**
    * Mutator,
    * @details updates scaleX
    * @param newX, the new scaleX
    */
    void UpdateScaleX(GLfloat newX);

    /**
    * Mutator,
    * @details updates scaleY
    * @param newY, the new scaleY
    */
    void UpdateScaleY(GLfloat newY);

    /**
    * Mutator,
    * @details updates scaleZ
    * @param newZ, the new scaleZ
    */
    void UpdateScaleZ(GLfloat newZ);

    /**
    * Extractor,
    * @details returns the scale matrix
    */
    mat4 GetScaleMatrix();
  private:
    /**
    * Helper,
    * @details updates the scale matrix
    */
    void UpdateScaleMat();

    GLfloat scaleX;
    GLfloat scaleY;
    GLfloat scaleZ;
    mat4 scaleMatrix;
  };
}
#endif
