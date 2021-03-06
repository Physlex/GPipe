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
     Transform(Al::Rotation _rotMat, Al::Translation _transMat, Al::Scale _scaleMat);

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
     void UpdateTranslation(Al::Translation newLoc);

     /**
     * Mutator,
     * Updates scale matrix
     */
     void UpdateScale(Al::Scale newSca);

     /**
     * Extractor,
     * Returns the current value of modelMat
     */
     mat4 GetTransform();
   private:
     Al::Rotation rotMat;
     Al::Translation translationMat;
     Al::Scale scaleMat;
     mat4 transMat;
  };
}
#endif
