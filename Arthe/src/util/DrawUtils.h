#pragma once
#include <GLFW/glfw3.h>
#include "Color.h"
#include "Image.h"
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
	}

	static void clear(Color color) {
		glClearColor(color.getR(), color.getG(), color.getB(), color.getA());
		glClear(GL_COLOR_BUFFER_BIT);
	}

	static void texture(Image image, int x, int y, float scaleX, float scaleY) {
		int width = image.width * scaleY;
		int height = image.height * scaleY;
		image.bind();
		glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x, y + height);
		glVertex2i(x + width, y + height);
		glVertex2i(x + width, y);
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	static void texture(Image image, int x, int y, float scale) {
		texture(image, x, y, scale, scale);
	}

	static void texture(Image image, int x, int y) {
		texture(image, x, y, 1.0);
	}

    
};

