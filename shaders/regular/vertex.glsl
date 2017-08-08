#version 450 core

#extension GL_ARB_bindless_texture : require

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec3 in_normal;

layout (std140) uniform RenderMatrices {
  mat4 projection;
  mat4 view;
} renderMatrices;

uniform mat4 model;

out vec3 vs_frag_pos;
out vec3 vs_normal;

void main()
{
    gl_Position = renderMatrices.projection * renderMatrices.view * model * vec4(in_position, 1.0f);

    vs_frag_pos = vec3(model * vec4(in_position, 1.0));

    vs_normal = normalize(mat3(transpose(inverse(model))) * in_normal);
}