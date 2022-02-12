#include "Rotation.h"

///Constructors

Al::Rotation::Rotation(GLfloat _thetaX, GLfloat _thetaY, GLfloat _thetaZ)
  : thetaX(_thetaX), thetaY(_thetaY), thetaZ(_thetaZ) {
  thetaX = _thetaX;
  thetaY = _thetaY;
  thetaZ = _thetaZ;
}

///Mutators/Extractors

void Al::Rotation::UpdateRotation(GLfloat newX, GLfloat newY, GLfloat newZ) {
  thetaX = newX;
  thetaY = newY;
  thetaZ = newZ;
  rotMatrix = RotateX(thetaX) * RotateY(thetaY) * RotateZ(thetaZ);
}

mat4 Al::Rotation::GetRotationMatrix() {
  return rotMatrix;
}
