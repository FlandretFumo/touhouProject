#version 460 core
out vec4 FragColor;

in vec2 uv;

uniform sampler2D samplerTexture;

void main()
{
	FragColor = vec4(0,0,0,1);
}