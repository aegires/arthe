#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <GLFW/glfw3.h>
class Image
{
private:
	unsigned char* image;
public:
	int width;
	int height;
	int channels;
	unsigned int glTexture;
	Image() {}
	Image(const char* path, bool isPixeled) {
		image = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);
		if (image == nullptr)
			throw("Image not exists: ", path);
		glGenTextures(1, &glTexture);
		glBindTexture(GL_TEXTURE_2D, glTexture);
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		if (isPixeled)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_CLAMP);
		else
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		if (channels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
		else if (channels == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);

		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void bind() {
		glBindTexture(GL_TEXTURE_2D, glTexture);
	}

	~Image() {
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(image);
	}
};

