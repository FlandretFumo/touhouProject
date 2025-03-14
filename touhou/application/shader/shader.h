#pragma once
#include<string>
#include"../../golb.h"
class Shader{
public:
	Shader();
	Shader(std::string vertexShaderPath, std::string frameShaderPath);
	~Shader();
	int createShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	int bindShader();
	int unbindShader();
	int getERROR(GLuint program, bool isShader);
	int IntUniform(std::string name,int value);
	int Float3Uniform(std::string name, float R, float G, float B);
	int FloatUniform(std::string name, float f);
	void setMatrix4x4(const std::string& name, glm::mat4 value);
private:
	GLuint shaderProgram{0};
};