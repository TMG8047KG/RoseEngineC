#version 460 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixin;
uniform float cock;

void main()
{
    FragColor = vec4(sin(cock), 0.0f, sin(cock), 1.0f) *mix(texture(texture1, TexCoord), texture(texture2, vec2(-TexCoord.x, TexCoord.y)), mixin);
}