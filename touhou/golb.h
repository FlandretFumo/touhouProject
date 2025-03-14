#pragma once
#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"../../wrapper/checkError.h"
#include<fstream>
#include<sstream>
#include<filesystem>
//#include<iostream>
#include<atomic>
#include<new>
#include<cstdlib>
#include<string>
#include<vector>
#include"../../application/media/media.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<Windows.h>
#include"../../application/media/gameTick.h"
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>


#define U8WindowName u8"東方恋之梦"

#define WindowName "東方恋之梦"

#define TEXT_TEXTURE_UNIT 1 

#define STD_PIX_SIZE 0.01
#define HEIGHT 1024
#define WIDTH 1280

#define ALL true
#define SINGLE false
#define TEXT 32164


#define PLAYER 1
#define BULLET 2
#define ENEMY 3
#define ENEMY_BULLET 4
#define M_PI 3.14159265358979323846
//#define HEIGHT 1080
//#define WIDTH 1920