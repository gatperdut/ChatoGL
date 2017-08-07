#version 450 core

layout (location = 0) in vec3 position;

layout (std140) uniform RenderMatrices {
  mat4 projection;
  mat4 view;
} renderMatrices;

out vec3 vs_tex_coord;

void main() {
  mat4 static_view = mat4(mat3(renderMatrices.view));
  vs_tex_coord = position;
  gl_Position = renderMatrices.projection * static_view * vec4(position, 1.0f);
}