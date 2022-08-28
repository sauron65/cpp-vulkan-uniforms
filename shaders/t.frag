#version 450

layout(location = 0) out vec4 glFragColor;
layout(location = 0) in vec3 v_color;

void main() {
  glFragColor = vec4(v_color, 1.0);
}