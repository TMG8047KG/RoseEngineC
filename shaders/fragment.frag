#version 460 core
out vec4 FragColor;

//in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;
in vec3 LightPos;

//uniform sampler2D texture1;
//uniform sampler2D texture2;
//uniform float mixin;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
//    FragColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(-TexCoord.x, TexCoord.y)), mixin);

//    FragColor = vec4(lightColor * objectColor, 1.0);

    // ambient
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(LightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // specular
    float specularStrength = 0.5;
    vec3 viewDir = normalize(-FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}