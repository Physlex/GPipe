#include "Scale.h"

///Constructors

Al::Scale::Scale(GLfloat _scaleX, GLfloat _scaleY, GLfloat _scaleZ)
  : scaleX(_scaleX), scaleY(_scaleY), scaleZ(_scaleZ) {
  scaleX = _scaleX;
  scaleY = _scaleY;
  scaleZ = _scaleZ;
  UpdateScale(scaleX, scaleY, scaleZ);
}

///Mutators/Extractors

void Al::Scale::UpdateScale(GLfloat newX, GLfloat newY, GLfloat newZ) {
  scaleX = newX;
  scaleY = newY;
  scaleZ = newZ;
  scaleMatrix = Angel::Scale(scaleX, scaleY, scaleZ);
}

mat4 Al::Scale::GetScaleMatrix() {
  return scaleMatrix;
}
