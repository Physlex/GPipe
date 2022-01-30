#ifndef CUBE_H
#define CUBE_H

#include <Angel.h>

const int MAXPOINTS = 4;

struct Cube {

  Cube(GLint _x, GLint _y, GLint _z, GLint _w)
    : x(_x), y(_y), z(_z), w(_w) {
      x = _x;
      y = _y;
      z = _z;
      w = _w;
  }


  vec2 vertexData[MAXPOINTS] = {
    vec2(.5,-.5),
    vec2(-.5),
    vec2(-.5,.5),
    vec2(.5),
  };

  GLint x; GLint y; GLint z; GLint w;
};

#endif
