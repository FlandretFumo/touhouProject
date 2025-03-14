#version 460 core
out vec4 FragColor;

in vec2 uv;

uniform sampler2D samplerTexture;

void main()
{
	vec4 color = texture(samplerTexture, uv);
	float remderColor = (color.r+color.g+color.b)/3;
	FragColor = vec4(remderColor,remderColor,remderColor,color.a);
}