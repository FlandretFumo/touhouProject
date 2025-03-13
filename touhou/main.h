#pragma once

#include"golb.h"
#include"../../application/Texture/texture.h"
#include"../../application/shader/shader.h"
#include"../../application/list/uv/uv.h"
#include"../../application/list/vao/vao.h"
#include"../../application/list/vbo/vbo.h"
#include"../../application/list/ebo/ebo.h"


void render();
static void  windowFrameSize(GLFWwindow* window, int width, int height);
static void  windowKeyEvent(GLFWwindow* window, int keyEvent, int scancode, int action, int mods);
