#version 450 core

in vec3 vs_tex_coord;

out vec4 color;

layout (binding = 0) uniform samplerCube skybox;

void main() {
  color = texture(skybox, vs_tex_coord);
}
