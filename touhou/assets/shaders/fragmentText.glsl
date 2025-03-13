#version 460 core
out vec4 FragColor;

in vec2 uv;

uniform sampler2D samplerTexture;
uniform vec3 color;
uniform vec2 alpah;
void main()
{
	vec4 tex = texture(samplerTexture, uv);
	FragColor = vec4(color.rgb,tex.r*alpah.r);
}