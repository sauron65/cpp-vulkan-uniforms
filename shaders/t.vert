#version 450

layout(location = 0) in vec2 a_position;
layout(location = 1) in vec3 a_color;

layout(location = 0) out vec3 v_color;

layout(binding = 0) uniform UniformBufferObject {
  mat4 model;
  mat4 view;
  mat4 projection;
} ubo;

void main() {
  gl_Position = ubo.projection * ubo.view * ubo.model * vec4(a_position, 0.0, 1.0);
  v_color = a_color;
}