#pragma once
#include <GLFW/glfw3.h>
#include "Color.h"
class DrawUtils
{
public:
	static void rect(int x, int y, int width, int height, Color color = Color::White()) {
		glColor4f(color.getR(), color.getG(), color.getB(), color.getA());
		glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x, y + height);
		glVertex2i(x + width, y + height);
		glVertex2i(x + width, y);
		glEnd();
		glFlush();
	}

	static void clear(Color color) {
		glClearColor(color.getR(), color.getG(), color.getB(), color.getA());
		glClear(GL_COLOR_BUFFER_BIT);
	}
};

