#include <iostream>
#include <Windows.h>
#include <math.h>
#include "header.h"

float clamp(float value, float min, float max);

int main(int argc, char* argv[]){

	const int width = 120;
	const int height = 30;
	const int len = width * height;

	float aspect = (float)width / height;
	float pixAscpect = 11.0f / 24.0f;
	char gradient[] = " .:!/r(l1Z4H9W8$@";
	int gradientSize = 15;

	char * screen = new char[width*height+1];
	screen[width*height] = '\0';

	for(int f = 0; f < 10000; f++){
		for(int i = 0; i < width; i++){
			for(int j = 0; j < height; j++){
				float x = (float)i / width * 2.0f - 1.0f;
				float y = (float)j / height * 2.0f - 1.0f;

				x *= aspect * pixAscpect;
				x += sin(f * 0.001);
				char pixel = ' ';
				float dist = sqrt(x*x + y*y);
				int color = (int)(1.0f / dist);

				color = clamp(color, 0, gradientSize);
				
				pixel = gradient[color];
				screen[i + j * width] = pixel;
			}
		}
		printf(screen);
	}
	system("pause");
	return 0;
}