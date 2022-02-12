#include "Rotation.h"

///Constructors

Al::Rotation::Rotation(GLfloat _thetaX, GLfloat _thetaY, GLfloat _thetaZ)
  : thetaX(_thetaX), thetaY(_thetaY), thetaZ(_thetaZ) {
  thetaX = _thetaX;
  thetaY = _thetaY;
  thetaZ = _thetaZ;
  UpdateRotation(thetaX, thetaY, thetaZ);
}

///Mutators/Extractors

void Al::Rotation::UpdateRotation(GLfloat newX, GLfloat newY, GLfloat newZ) {
  thetaX = newX;
  thetaY = newY;
  thetaZ = newZ;
  UpdateMatrix();
}

void Al::Rotation::UpdateRotationX(GLfloat newX) {
  thetaX = newX;
  UpdateMatrix();
}

void Al::Rotation::UpdateRotationY(GLfloat newY) {
  thetaY = newY;
  UpdateMatrix();
}

void Al::Rotation::UpdateRotationZ(GLfloat newZ) {
  thetaZ = newZ;
  UpdateMatrix();
}

mat4 Al::Rotation::GetRotationMatrix() {
  return rotMatrix;
}

///Helpers

void Al::Rotation::UpdateMatrix() {
  rotMatrix = Angel::RotateX(thetaX) * Angel::RotateY(thetaY) * Angel::RotateZ(thetaZ);
}
