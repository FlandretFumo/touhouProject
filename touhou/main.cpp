#include"main.h"
#include"game.h"
#pragma comment(lib, "strmiids.lib")  

GLuint program;


struct structVAO
{
	RenderObject* vao;
	struct structVBO* next;
};


void mousePosition(GLFWwindow* window, double xpos, double ypos) {
		mouseClick(xpos, ypos);
}
void mouseClick(GLFWwindow* window, int button, int action, int mods) {
	if (action) {
		click(true,button);
	}
	else {
		click(false, -1);
	}
}
GLFWwindow* window;
//MediaPlay * select;
int main() {
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Òþ²Ø±ß¿ò
	//glfwWindowHint(GLFW_DECORATED, GL_FALSE);
	
	window = glfwCreateWindow(WIDTH,HEIGHT, U8WindowName,NULL,NULL);
	if (!window) return -1;
	glfwMakeContextCurrent(window);
	//glfwSetWindowTitle(window, "¶«·½");
	glfwSetWindowSizeLimits(window, WIDTH, HEIGHT, WIDTH, HEIGHT);
	//Òþ²ØÊó±ê
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	glfwSetFramebufferSizeCallback(window, windowFrameSize);
	glfwSetKeyCallback(window, windowKeyEvent);
	glfwSetCursorPosCallback(window, mousePosition);
	glfwSetMouseButtonCallback(window, mouseClick);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "GET_GLAD_INTERFACE_ERROR";
	}
	glfwSwapInterval(1);
	glViewport(0, 0, WIDTH, HEIGHT);
	glClearColor(0.9F, 0.9F, 0.9F, 1.0F);
	initializeGame();
	std::cout << "ÇëÎðÍÏ¶¯´°¿Ú" << std::endl;

	while (!glfwWindowShouldClose(window)&& isRun()) {
		glfwPollEvents();
		GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
		render();
		glfwSwapBuffers(window);
	}
	clearGame();
	glfwTerminate();
	return 0;
}
static void  windowFrameSize(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);

}
int select_value = 0;
#define MAX_KEY 1
#define MIN_KEY 0
static void  windowKeyEvent(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action==1) {
		keyEvent(key);
	}
	
}



void render() {
	gameLogic(window);
}