#pragma once
#include "LogUtils.h"
#include <GLFW/glfw3.h>
#include <Windows.h>
#include <format>

class GameAdapter {
public:
	virtual void load() = 0;
	virtual void update(float delta) = 0;
	virtual void draw() = 0;
	virtual void unload() = 0;
	void run(const char* title, int width, int height, bool hideConsole = true) {
		if (hideConsole)
			ShowWindow(GetConsoleWindow(), SW_HIDE);
		if (!glfwInit()) {
			throw("Couldn't initializate glfw!");
			LogUtils::error();
		}
		GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);

		if (!window) {
			throw("Couldn't create window!");
			LogUtils::error();
		}
		
		double currentFrame = glfwGetTime();
		double lastFrame = currentFrame;
		double deltaTime;
		int lastWidth = 0, winWidth;
		int lastHeight = 0, winHeight;

		//parameters
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		

		glfwMakeContextCurrent(window);
		glfwSwapInterval(1);

		load();
		while (!glfwWindowShouldClose(window)) {
			currentFrame = glfwGetTime();
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;
			
			glfwGetWindowSize(window, &winWidth, &winHeight);

			if (winWidth != lastWidth || winHeight != lastHeight)
				resize(winWidth, winHeight);

			lastWidth = winWidth;
			lastHeight = winHeight;

			update((float)deltaTime);
			draw();

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		
		unload();
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	
	void resize(int width, int height) {
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, width, 0, height, 0, 1);
		glMatrixMode(GL_MODELVIEW);
		cout << "Resized to " << width << " " << height << endl;
	}
};