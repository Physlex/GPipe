/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#include "Component.h"
#include <Angel.h>

GLfloat Al::Component::UpdateX(GLfloat value) {
  return positionData.UpdateXCoord(value);
}

GLfloat Al::Component::UpdateY(GLfloat value) {
  return positionData.UpdateYCoord(value);
}

GLfloat Al::Component::UpdateZ(GLfloat value) {
  return positionData.UpdateZCoord(value);
}

GLfloat Al::Component::X() {
  return positionData.GetX();
}

GLfloat Al::Component::Y() {
  return positionData.GetY();
}

GLfloat Al::Component::Z() {
  return positionData.GetZ();
}

mat4 Al::Component::Matrix() {
  return matrixData;
}


Al::Location::Location(GLfloat X, GLfloat Y, GLfloat Z) {
  positionData = Coords(X, Y, Z);
}

mat4 Al::Location::CreateWorldMat() {
  matrixData = Angel::Translate(positionData.GetX(),
                                positionData.GetY(),
                                positionData.GetZ());
  return matrixData;
}


Al::Rotation::Rotation(GLfloat Xtheta, GLfloat Ytheta, GLfloat Ztheta) {
  positionData = Coords(Xtheta, Ytheta, Ztheta);
}

mat4 Al::Rotation::CreateWorldMat() {
  matrixData = Angel::RotateX(positionData.GetX()) *
               Angel::RotateY(positionData.GetY()) *
               Angel::RotateZ(positionData.GetZ());
  return matrixData;
}


Al::Scale::Scale(GLfloat X, GLfloat Y, GLfloat Z) {
  positionData = Coords(X, Y, Z);
}

mat4 Al::Scale::CreateWorldMat() {
  matrixData = Angel::Scale(positionData.GetX(),
                            positionData.GetY(),
                            positionData.GetZ());
  return matrixData;
}
