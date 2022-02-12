#ifndef TRANSFORM_H
#define TRANSFORM_H

//Includes for use in all transform related tasks//
#include "Translation.h"
#include "Rotation.h"
#include "Scale.h"
#include <Angel.h>
///////////////////////////////////////////////////
namespace Al {
  /**
  * @class Transform Transform.h "Transform.h"
  * @details Creates a transform model matrix our of
  * a translation, rotation and scale matrix
  */
  class Transform {
   public:
     /**
     * Constructor,
     * Creates a transform from a translation, rotation and scale matrix
     */
     Transform(Al::Translation transMat, Al::Rotation rotMat, Al::Scale scaleMat);

     /**
     * Mutator,
     * Updates all params in transform
     */
     void UpdateAll(Al::Rotation newRot, Al::Translation newTrans, Al::Scale newScale);

     /**
     * Mutator,
     * Updates rotation matrix
     */
     void UpdateRotation(Al::Rotation newRot);

     /**
     * Mutator,
     * Updates location matrix
     */
     void UpdateLocation(Al::Translation newLoc);

     /**
     * Mutator,
     * Updates scale matrix
     */
     void UpdateScaleMatrix(Al::Location newSca);

     /**
     * Extractor,
     * Returns the current value of modelMat
     */
     mat4 GetTransform();
   private:
     mat4 modelMat;
  };
}
#endif
