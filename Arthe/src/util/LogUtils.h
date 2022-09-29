#pragma once
#include <iostream>
#include <GLFW/glfw3.h>
using namespace std;

class LogUtils
{
public:
	static void error() {
		glfwTerminate();
		exit(1);
	}
};