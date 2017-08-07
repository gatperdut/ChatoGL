#version 450 core

layout (location = 0) in vec3 position;

layout (std140) uniform RenderMatrices {
  mat4 projection;
  mat4 view;
} renderMatrices;

uniform mat4 model;

void main() {
  gl_Position = renderMatrices.projection * renderMatrices.view * model * vec4(position, 1.0);
}