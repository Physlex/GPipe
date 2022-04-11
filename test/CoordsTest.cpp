/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#include "Coords.h"
#include <iostream>
#include <string>

namespace Test {
void Print(std::string input) {
  std::cout << input << std::endl;
}

bool TestCoord() {
  Print("Testing constructor");
  Al::Coords* c1 = new Al::Coords(1.2, 1.3, 14.5);

  Print("Testing X return");
  if (static_cast<int>(c1->GetX()) != 1) {
    return false;
  }
  Print("Testing Y return");
  if (static_cast<int>(c1->GetY()) != 1) {
    return false;
  }
  Print("Testing Z return");
  if (static_cast<int>(c1->GetZ()) != 14) {
    return false;
  }

  Print("Testing UpdateX");
  if (static_cast<int>(c1->UpdateXCoord(2)) != static_cast<int>(1.2+2)) {
    return false;
  }
  Print("Testing UpdateY");
  if (static_cast<int>(c1->UpdateYCoord(2)) != static_cast<int>(1.3+2)) {
    return false;
  }
  Print("Testing UpdateZ");
  if (static_cast<int>(c1->UpdateZCoord(2)) != static_cast<int>(14.5+2)) {
    return false;
  }

  delete c1;
  return true;
}
}
