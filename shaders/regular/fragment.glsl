#version 450 core

#extension GL_ARB_bindless_texture : require

struct Attenuation {
  float constant;
  float linear;
  float quadratic;
};

struct DirectionalLight {
  sampler2DShadow shadowTexture;
  float intensity;
  float shininess;
  vec3 direction;
  mat4 viewMatrix;
  mat4 projectionMatrix;
};

struct PointLight {
  vec3 pos;
  float intensity;
  float shininess;
  Attenuation attenuation;
};

struct SpotLight {
  vec3 pos;
  vec3 dir;
  float cutoff;
  float intensity;
  float shininess;
  Attenuation attenuation;
};


layout (std140, binding = 0) uniform Material {
  vec4 diffuse;
} material;

layout (std430, binding = 1) buffer DirectionalLights {
  DirectionalLight directionalLights[];
};

layout (std430, binding = 2) buffer PointLights {
  PointLight pointLights[];
};

layout (std430, binding = 3) buffer SpotLights {
  SpotLight spotLights[];
};

uniform vec3 campos;

in vec3 vs_frag_pos;
in vec3 vs_normal;

out vec4 color;

mat4 shadowMatrixBias = mat4(
  vec4(0.5f, 0.0f, 0.0f, 0.0f),
  vec4(0.0f, 0.5f, 0.0f, 0.0f),
  vec4(0.0f, 0.0f, 0.5f, 0.0f),
  vec4(0.5f, 0.5f, 0.5f, 1.0f)
);

void main() {
  vec3 diffuse = vec3(0.0);
  vec3 specular = vec3(0.0);

  DirectionalLight dlight;
  for (int i = 0; i < directionalLights.length(); i++) {
    dlight = directionalLights[i];
    vec3 lightdir = normalize(dlight.direction);

    vec3 viewdir = normalize(campos - vs_frag_pos);

    float diffusefactor = max(dot(vs_normal, lightdir), 0.0);

    vec3 halfvector = normalize(lightdir + viewdir);
    float specularfactor = max(dot(vs_normal, halfvector), 0.0);
    specularfactor = pow(specularfactor, dlight.shininess);

    float f = textureProj(dlight.shadowTexture, shadowMatrixBias * dlight.projectionMatrix * dlight.viewMatrix * vec4(vs_frag_pos, 1.0));
    
    diffusefactor *= f;
    specularfactor *= f;

    if (diffusefactor > 0.0) {
      diffuse += vec3(dlight.intensity) * diffusefactor;
      specular += vec3(dlight.intensity) * specularfactor;
    }
  }

  PointLight plight;
  for (int i = 0; i < pointLights.length(); i++) {
    plight = pointLights[i];
    vec3 lightdir = plight.pos - vs_frag_pos;
    float lightdistance = length(lightdir);
    lightdir = normalize(lightdir);
    vec3 viewdir = normalize(campos - vs_frag_pos);

    float attenuation = 1.0 / (plight.attenuation.constant +
                               plight.attenuation.linear * lightdistance +
                               plight.attenuation.quadratic * pow(lightdistance, 2)
                              );

    float diffusefactor = max(dot(vs_normal, lightdir), 0.0);

    vec3 halfvector = normalize(lightdir + viewdir);
    float specularfactor = max(dot(vs_normal, halfvector), 0.0);
    specularfactor = pow(specularfactor, plight.shininess);

    if (diffusefactor > 0.0) {
      diffuse += vec3(plight.intensity) * diffusefactor * attenuation;
      specular += vec3(plight.intensity) * specularfactor * attenuation;
    }
  }

  SpotLight slight;
  for (int i = 0; i < spotLights.length(); i++) {
    slight = spotLights[i];
    vec3 lightdir = slight.pos - vs_frag_pos;
    float lightdistance = length(lightdir);
    lightdir = normalize(lightdir);
    vec3 viewdir = normalize(campos - vs_frag_pos);

    float attenuation = 1.0 / (slight.attenuation.constant +
                               slight.attenuation.linear * lightdistance +
                               slight.attenuation.quadratic * pow(lightdistance, 2)
                              );
    
    float spotcos = dot(lightdir, -normalize(slight.dir));
    attenuation *= spotcos < slight.cutoff ? 0.0 : pow(spotcos, 16);

    float diffusefactor = max(dot(vs_normal, lightdir), 0.0);

    vec3 halfvector = normalize(lightdir + viewdir);
    float specularfactor = max(dot(vs_normal, halfvector), 0.0);
    specularfactor = pow(specularfactor, slight.shininess);

    if (diffusefactor > 0.0) {
      diffuse += vec3(slight.intensity) * diffusefactor * attenuation;
      specular += vec3(slight.intensity) * specularfactor * attenuation;
    }
  }

  color = min(
    //vec4(0.5, 0.5, 0.5, 1.0) * vec4(diffuse, 1.0) + vec4(specular, 1.0),
    material.diffuse * vec4(diffuse, 1.0) + vec4(specular, 1.0),
    vec4(1.0)
  );

}
