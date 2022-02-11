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
  private:
    GLfloat scaleX;
    GLfloat scaleY;
    GLfloat scaleZ;
    mat4 scaleMatrix;
  };
}
#endif
