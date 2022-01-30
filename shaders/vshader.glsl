#version 150

in vec4 vPosition;
uniform float uTheta;
out vec4 vColour;

void main() {
  gl_Position.x = -sin(uTheta) * vPosition.x + cos(uTheta) * vPosition.y;
  gl_Position.y =  sin(uTheta) * vPosition.y + cos(uTheta) * vPosition.x;
  gl_Position.z = 0.0;
  gl_Position.w = 1.0;

  vec4 colour[5];
  colour[0] = vec4(1.0, 0, 0, 1.0);
  colour[1] = vec4(0, 1.0, 0, 1.0);
  colour[2] = vec4(0, 0, 1.0, 1.0);
  colour[3] = vec4(0, 0, 1, 1.0);
  colour[4] = vec4(1, 1, 1, 1.0);

  vColour = colour[gl_VertexID];
}
