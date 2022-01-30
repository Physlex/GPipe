#include "../include/Alex/Object.h"

//Constructors

Object::Object(GPenum target) {
  state = target;
}

Object::~Object() {
  delete cubeData;
}

//Public fields

vec2 *Object::GetTarget() {
  switch (state) {
    case (CUBE):
    return CreateCubeObj();
    break;
  }
  return nullptr;
}

vec2 *Object::CreateCubeObj(void) {
  cubeData = new Cube(.5, .5, -1, 1);
  cubeVertexData = cubeData->vertexData;
  return cubeVertexData;
}
