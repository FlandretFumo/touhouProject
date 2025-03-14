#version 460 core
out vec4 FragColor;

in vec2 uv;

uniform sampler2D samplerTexture;

void main()
{
	vec4 tex = texture(samplerTexture, uv);
	FragColor = vec4(tex.rgb,1.0);
}