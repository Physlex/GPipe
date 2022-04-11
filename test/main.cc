#include "CoordsTest.cpp"

int main(int argv, char** argc) {
  if (Test::TestCoord() == false) {
    std::cout << "Coord Test Fail." << std::endl;
  } else {
    std::cout << "Coord Test Pass." << std::endl;
  }
}
