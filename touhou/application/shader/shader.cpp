#include"shader.h"
Shader::Shader() {
};
Shader::Shader(std::string vertexShaderPath, std::string frameShaderPath) {
	createShader(vertexShaderPath, frameShaderPath);
}
Shader::~Shader() {
	glDeleteProgram(shaderProgram);
}
int Shader::createShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    std::ifstream vertexFile(vertexShaderPath, std::ios::in | std::ios::binary);
    std::ifstream fragmentFile(fragmentShaderPath, std::ios::in | std::ios::binary);

    if (!vertexFile.is_open()) {
        std::cerr << "Failed to open vertex shader file: " << vertexShaderPath << std::endl;
        return -1;
    }
    if (!fragmentFile.is_open()) {
        std::cerr << "Failed to open fragment shader file: " << fragmentShaderPath << std::endl;
        vertexFile.close();
        return -1;
    }

    std::stringstream buffer1, buffer2;
    buffer1 << vertexFile.rdbuf();
    buffer2 << fragmentFile.rdbuf();

    std::string vertexCode = buffer1.str();
    std::string fragmentCode = buffer2.str();

    vertexFile.close();
    fragmentFile.close();

    const char* vs = vertexCode.c_str();
    const char* fs = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertexShader, 1, &vs, nullptr);
    glShaderSource(fragmentShader, 1, &fs, nullptr);

    glCompileShader(vertexShader);
    if (!getERROR(vertexShader, true)) {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return -1;
    }

    glCompileShader(fragmentShader);
    if (!getERROR(fragmentShader, true)) {
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return -1;
    }

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);
    if (!getERROR(shaderProgram, false)) {
        glDeleteProgram(shaderProgram);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return -1;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return 0;
}

int Shader::bindShader() {
    glUseProgram(shaderProgram);
    return 0;
}

int Shader::unbindShader() {
    glUseProgram(0);
    return 0;
}

int Shader::getERROR(GLuint program, bool isShader) {
    char log[1024];
    GLint success;
    GLchar infoLog[512];

    if (isShader) {
        glGetShaderiv(program, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(program, 512, NULL, infoLog);
        }
    }
    else {
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
        }
    }

    if (!success) {
        std::cout << "ERROR:\n" << infoLog << std::endl;
        return 0;
    }
    return 1;
}
int Shader::IntUniform(std::string name,int value) {
	GLuint location =  glGetUniformLocation(shaderProgram, name.c_str());
	glUniform1i(location, value);
	return 0;
}
int Shader::Float3Uniform(std::string name, float R, float G, float B) {
    GLuint location = glGetUniformLocation(shaderProgram, name.c_str());
    glUniform3f(location, R, G, B);
    return 0;
}
int Shader::FloatUniform(std::string name,float f) {
    GLuint location = glGetUniformLocation(shaderProgram,name.c_str());
    glUniform2f(location,f,f);
    return 0;
}

void Shader::setMatrix4x4(const std::string& name, glm::mat4 value) {
    //1 通过名称拿到Uniform变量的位置Location
    GLint location = glGetUniformLocation(shaderProgram, name.c_str());

    //2 通过Location更新Uniform变量的值
    //transpose参数：表示是否对传输进去的矩阵数据进行转置
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
}