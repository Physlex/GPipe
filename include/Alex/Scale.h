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
    * Mutator,
    * @details updates scalex,y,z with newx,y,z
    * @param newX, the new version of scaleX
    * @param newY, the new version of scaleY
    * @param newZ, the new version of scaleZ
    */
    void UpdateScale(GLfloat newX,GLfloat newY,GLfloat newZ);
    /**
    * Extractor,
    * @details returns the scale matrix
    */
    mat4 GetScaleMatrix();
  private:
    GLfloat scaleX;
    GLfloat scaleY;
    GLfloat scaleZ;
    mat4 scaleMatrix;
  };
}
#endif
