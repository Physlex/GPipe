#include "Transform.h"

///Constructors

Al::Transform::Transform(Al::Rotation _rotMat, Al::Translation _translationMat, Al::Scale _scaleMat)
  : rotMat(_rotMat), translationMat(_translationMat), scaleMat(_scaleMat) {
  rotMat = _rotMat;
  translationMat = _translationMat;
  scaleMat = _scaleMat;
}

///Mutators/Extractors

void Al::Transform::UpdateAll(Al::Rotation newRot, Al::Translation translationMat, Al::Scale newSca) {
  UpdateRotation(newRot);
  UpdateTranslation(translationMat);
  UpdateScale(newSca);
}

void Al::Transform::UpdateRotation(Al::Rotation newRot) {
  rotMat = newRot;
}

void Al::Transform::UpdateTranslation(Al::Translation newLoc) {
  translationMat = newLoc;
}

void Al::Transform::UpdateScale(Al::Scale newSca) {
  scaleMat = newSca;
}

mat4 Al::Transform::GetTransform() {
  transMat =    scaleMat.GetScaleMatrix()
              * rotMat.GetRotationMatrix()
              * translationMat.GetTransMatrix();
  return transMat;
}
