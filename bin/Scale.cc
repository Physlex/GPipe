#include "Scale.h"

///Constructors

Al::Scale::Scale(GLfloat _scaleX, GLfloat _scaleY, GLfloat _scaleZ)
  : scaleX(_scaleX), scaleY(_scaleY), scaleZ(_scaleZ) {
  scaleX = _scaleX;
  scaleY = _scaleY;
  scaleZ = _scaleZ;
  UpdateScaleMat();
}

///Methods

Al::Scale Al::Scale::operator-(GLfloat factor) {
  Al::Scale scaleTemp(scaleX, scaleY, scaleZ);
  scaleTemp -= factor;
  return scaleTemp;
}

Al::Scale Al::Scale::operator-=(GLfloat factor) {
    scaleX -= factor;
    scaleY -= factor;
    scaleZ -= factor;
    UpdateScaleMat();
    return *this;
}

Al::Scale Al::Scale::operator+(GLfloat factor) {
  Al::Scale scaleTemp(scaleX, scaleY, scaleZ);
  scaleTemp += factor;
  return scaleTemp;
}

Al::Scale Al::Scale::operator+=(GLfloat factor) {
  scaleX += factor;
  scaleY += factor;
  scaleZ += factor;
  UpdateScaleMat();
  return *this;
}

Al::Scale Al::Scale::operator*(GLfloat factor) {
  Al::Scale scaleTemp(scaleX, scaleY, scaleZ);
  scaleTemp *= factor;
  return scaleTemp;
}

Al::Scale Al::Scale::operator*=(GLfloat factor) {
  scaleX *= factor;
  scaleY *= factor;
  scaleZ *= factor;
  UpdateScaleMat();
  return *this;
}

Al::Scale Al::Scale::operator/(GLfloat factor) {
  Al::Scale scaleTemp(scaleX, scaleY, scaleZ);
  scaleTemp /= factor;
  return scaleTemp;
}

Al::Scale Al::Scale::operator/=(GLfloat factor) {
  scaleX /= factor;
  scaleY /= factor;
  scaleZ /= factor;
  UpdateScaleMat();
  return *this;
}

///Mutators/Extractors

void Al::Scale::UpdateScale(GLfloat newX, GLfloat newY, GLfloat newZ) {
  scaleX = newX;
  scaleY = newY;
  scaleZ = newZ;
  UpdateScaleMat();
}

void Al::Scale::UpdateScaleX(GLfloat newX) {
  scaleX = newX;
  UpdateScaleMat();
}

void Al::Scale::UpdateScaleY(GLfloat newY) {
  scaleY = newY;
  UpdateScaleMat();
}

void Al::Scale::UpdateScaleZ(GLfloat newZ) {
  scaleZ = newZ;
  UpdateScaleMat();
}

mat4 Al::Scale::GetScaleMatrix() {
  return scaleMatrix;
}

///Helpers

void Al::Scale::UpdateScaleMat() {
  scaleMatrix = Angel::Scale(scaleX, scaleY, scaleZ);
}
