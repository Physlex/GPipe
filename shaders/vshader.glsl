#version 150

in vec4 vPosition;
uniform mat4 uModelView;
uniform mat4 uProjection;
out vec4 vColour;

void main() {
  gl_Position = vPosition;

  vec4 colour[4];
  colour[0] = vec4(1.0, 0.0, 0.0, 1.0);
  colour[1] = vec4(0.0, 1.0, 0.0, 1.0);
  colour[2] = vec4(0.0, 1.0, 0.0, 1.0);
  colour[3] = vec4(0.0, 0.0, 1.0, 1.0);
  vColour = colour[gl_VertexID];
}
