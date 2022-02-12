#include "Translation.h"

///Constructors

Al::Translation::Translation(GLfloat _posX, GLfloat _posY, GLfloat _posZ)
  : posX(_posX), posY(_posY), posZ(_posZ) {
  posX = _posX;
  posY = _posY;
  posZ = _posZ;
  UpdateTranslationMat();
}

///Methods

Al::Translation Al::Translation::operator-(GLfloat factor) {
  Al::Translation transTemp(posX, posY, posZ);
  transTemp -= factor;
  return transTemp;
}

Al::Translation Al::Translation::operator-=(GLfloat factor) {
    posX -= factor;
    posY -= factor;
    posZ -= factor;
    UpdateTranslationMat();
    return *this;
}

Al::Translation Al::Translation::operator+(GLfloat factor) {
  Al::Translation transTemp(posX, posY, posZ);
  transTemp += factor;
  return transTemp;
}

Al::Translation Al::Translation::operator+=(GLfloat factor) {
  posX += factor;
  posY += factor;
  posZ += factor;
  UpdateTranslationMat();
  return *this;
}

Al::Translation Al::Translation::operator*(GLfloat factor) {
  Al::Translation transTemp(posX, posY, posZ);
  transTemp *= factor;
  return transTemp;
}

Al::Translation Al::Translation::operator*=(GLfloat factor) {
  posX *= factor;
  posY *= factor;
  posZ *= factor;
  UpdateTranslationMat();
  return *this;
}

Al::Translation Al::Translation::operator/(GLfloat factor) {
  Al::Translation transTemp(posX, posY, posZ);
  transTemp /= factor;
  return transTemp;
}

Al::Translation Al::Translation::operator/=(GLfloat factor) {
  posX /= factor;
  posY /= factor;
  posZ /= factor;
  UpdateTranslationMat();
  return *this;
}

///Mutators/Extractors

void Al::Translation::UpdateTranslationX(GLfloat newX) {
  posX = newX;
  UpdateTranslationMat();
}

void Al::Translation::UpdateTranslationY(GLfloat newY) {
  posY = newY;
  UpdateTranslationMat();
}

void Al::Translation::UpdateTranslationZ(GLfloat newZ) {
  posZ = newZ;
  UpdateTranslationMat();
}

GLfloat Al::Translation::X() {
  return posX;
}

GLfloat Al::Translation::Y() {
  return posY;
}

GLfloat Al::Translation::Z() {
  return posZ;
}

mat4 Al::Translation::GetTransMatrix() {
  return transMatrix;
}

//Helpers

void Al::Translation::UpdateTranslationMat() {
  transMatrix = Angel::Translate(posX, posY, posZ);
}
