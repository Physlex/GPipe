/**
* Copyright 2022 Alexander Williams-Letondre
*/

/**
* @author Alexander Williams-Letondre <a.williamsletondre@uleth.ca>
* @date Spring 2020
*/

#ifndef INCLUDE_ALEX_COMPONENT_H_
#define INCLUDE_ALEX_COMPONENT_H_

#include "Coords.h"
#include <Angel.h>

namespace Al {

/**
* @class Component.h "Component.h"
* @brief Operates on coords and handles object matrix
* @details Wrapper for low-level coords class
*/
class Component {
 public:
  /**
  * @brief Updates the X Component
  * @details Interface to coords class
  * @return the component at X
  */
  GLfloat UpdateX(GLfloat value);

  /**
  * @brief Updates the Y Component
  * @details Interface to coords class
  * @return the component at Y
  */
  GLfloat UpdateY(GLfloat value);

  /**
  * @brief Updates the Z Component
  * @details Interface to coords class
  * @return the component at Z
  */
  GLfloat UpdateZ(GLfloat value);

  /**
  * @brief Implemented in derived classes
  */
  virtual mat4 CreateWorldMat(GLfloat value) = 0;

  /**
  * Extractors
  */
  GLfloat X();
  GLfloat Y();
  GLfloat Z();
  mat4 Matrix();

 protected:
  Al::Coords positionData;
  mat4 matrixData;
};

/**
* @class Location "Location"
* @brief Wrapper in relation to Position in world space
*/
class Location : public Component {
 public:
  /**
  * @brief Wrapper constructor for Coords class
  */
  Location(GLfloat X, GLfloat Y, GLfloat Z);

  /**
  * @brief Creates a location matrix
  * @details uses angel.h
  * @return matrixData
  */
  mat4 CreateWorldMat();
};

/**
* @class Rotation "Rotation"
* @brief Wrapper in relation to rotation in world space
*/
class Rotation : public Component {
 public:
  /**
  * @brief Wrapper constructor for Coords class
  */
  Rotation(GLfloat Xtheta, GLfloat Ytheta, GLfloat Ztheta);

  /**
  * @brief Creates a rotation matrix
  * @details uses angel.h
  * @return matrixData
  */
  mat4 CreateWorldMat();
};

/**
* @class Scale "Scale"
* @brief Wrapper in relation to Scale in world space
*/
class Scale : public Component {
 public:
  /**
  * @brief Wrapper constructor for Coords class
  */
  Scale(GLfloat X, GLfloat Y, GLfloat Z);

  /**
  * @brief Creates a scale matrix
  * @details uses angel.h
  * @return matrixData
  */
  mat4 CreateWorldMat();
};

}  // namespace Al

#endif  // INCLUDE_ALEX_COMPONENT_H_
