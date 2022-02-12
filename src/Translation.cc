#include "Translation.h"

///Constructors

Al::Translation::Translation(GLfloat _posX, GLfloat _posY, GLfloat _posZ)
  : posX(_posX), posY(_posY), posZ(_posZ) {
  posX = _posX;
  posY = _posY;
  posZ = _posZ;
  UpdateTranslation(posX, posY, posZ);
}

///Mutators/Extractors

void Al::Translation::UpdateTranslation(GLfloat newX, GLfloat newY, GLfloat newZ) {
  posX = newX;
  posY = newY;
  posZ = newZ;
  transMatrix = Angel::Translate(posX, posY, posZ);
}

mat4 Al::Translation::GetTransMatrix() {
  return transMatrix;
}
