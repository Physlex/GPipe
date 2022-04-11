/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#ifndef INCLUDE_ALEX_COORDS_H_
#define INCLUDE_ALEX_COORDS_H_

// IWYU
#include <Angel.h>
#include <vector>

namespace Al {
class Coords {
 public:
  /**
  * @brief default constructor
  */
  Coords();

  /**
  * @brief Stores data about X, Y, and Z in a 3dim system
  * @details Constructor
  * @param[in] X, the x component of 3 dim, homo, world space.
  * @param[in] Y, the y component of 3 dim, homo, world space.
  * @param[in] Z, the z component of 3 dim, homo, world space.
  */
  Coords(GLfloat X, GLfloat Y, GLfloat Z);

  /**
  * @brief Updates the x coordinate by an addition of value
  * @details used to "set" the X value dynamically
  * @param[in] the value to be adjusted by
  * @return GLfloat, the value created by addition of x.
  *                  Primarily used for testing.
  */
  GLfloat UpdateXCoord(GLfloat value);

  /**
  * @brief Updates the Y coordinate by an addition of value
  * @details used to "set" the Y value dynamically
  * @param[in] the value to be adjusted by
  * @return GLfloat, the value created by addition of Y.
  *                  Primarily used for testing.
  */
  GLfloat UpdateYCoord(GLfloat value);

  /**
  * @brief Updates the Z coordinate by an addition of value
  * @details used to "set" the Z value dynamically
  * @param[in] the value to be adjusted by
  * @return GLfloat, the value created by addition of Z.
  *                  Primarily used for testing.
  */
  GLfloat UpdateZCoord(GLfloat value);

  /**
  * Extractor methods
  */
  GLfloat GetX();
  GLfloat GetY();
  GLfloat GetZ();

 private:
  std::vector<GLfloat> coords;
};

}  // namespace Al

#endif  // INCLUDE_ALEX_COORDS_H_
