/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#include "CoordsTest.cpp"
#include "ComponentTest.cpp"

int main(int argv, char** argc) {
  if (Test::TestCoord() == false) {
    std::cout << "Coord Test Fail." << std::endl;
  } else {
    std::cout << "Coord Test Pass." << std::endl;
  }

  if (Test::TestComponent() == false) {
    Test::Print("Component Test Failed");
  } else {
    Test::Print("Component Test Passed");
  }
}
