/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#include "Coords.h"
#include <Angel.h>
#include <vector>

Al::Coords::Coords(GLfloat X, GLfloat Y, GLfloat Z) {
  coords.push_back(X);
  coords.push_back(Y);
  coords.push_back(Z);
}

GLfloat Al::Coords::UpdateXCoord(GLfloat value) {
  coords.at(0) += value;
  return coords.at(0);
}

GLfloat Al::Coords::UpdateYCoord(GLfloat value) {
  coords.at(1) += value;
  return coords.at(1);
}

GLfloat Al::Coords::UpdateZCoord(GLfloat value) {
  coords.at(2) += value;
  return coords.at(2);
}

GLfloat Al::Coords::GetX() {
  return coords.at(0);
}

GLfloat Al::Coords::GetY() {
  return coords.at(1);
}

GLfloat Al::Coords::GetZ() {
  return coords.at(2);
}
