#include "Transform.h"

///Constructors

Al::Transform::Transform(Al::Rotation _rotMat, Al::Translation _transMat, Al::Scale _scaleMat)
  : rotMat(_rotMat), transMat(_transMat), scaleMat(_scaleMat) {
  rotMat = _rotMat;
  transMat = _transMat;
  scaleMat = _scaleMat;
}

///Mutators/Extractors

void Al::Transform::UpdateAll(Al::Rotation newRot, Al::Translation newTrans, Al::Scale newSca) {
  UpdateRotation(newRot);
  UpdateLocation(newTrans);
  UpdateScale(newSca);
}

void Al::Transform::UpdateRotation(Al::Rotation newRot) {
  rotMat = newRot;
}

void Al::Transform::UpdateLocation(Al::Translation newLoc) {
  transMat = newLoc;
}

void Al::Transform::UpdateScale(Al::Scale newSca) {
  scaleMat = newSca;
}

// mat4 Al::Transform GetTransform() {
//
// }
