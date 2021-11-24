#include <iostream>
#include <Windows.h>

int main(int argc, char* argv[]){

	const int width = 120;
	const int height = 30;
	const int len = width * height;

	char * screen = new char[width*height+1];
	screen[width*height] = '\0';

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			float x = (float)i / width * 2.0f - 1.0f;
			float y = (float)j / height * 2.0f - 1.0f;

			char pixel = ' ';
			if(x*x + y*y < 0.5) pixel = '@';
			screen[i + j * width] = pixel;
		}
	}

	printf(screen);
	system("pause");
	return 0;
}