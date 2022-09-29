#pragma once
class Color
{
private:
	unsigned char red = 0, green = 0, blue = 0, alpha = 255;
public:
	Color(int r, int g, int b, int a) {
		red = r;
		green = g;
		blue = b;
		alpha = a;
	}
	
	float getR() {
		return (float)red / 255;
	}
	
	float getG() {
		return (float)green / 255;
	}
	
	float getB() {
		return (float)blue / 255;
	}
	
	float getA() {
		return (float)alpha / 255;
	}

	void setR(int value) {
		red = value;
	}

	void setG(int value) {
		green = value;
	}

	void setB(int value) {
		blue = value;
	}
	
	void setA(int value) {
		alpha = value;
	}
	
	static Color White() {
		return Color(255, 255, 255, 255);
	}
};
