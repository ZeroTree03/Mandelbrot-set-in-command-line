#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

int main()
{
	// Variables
	const int HEIGHT = 30;		// Standart console Height
	const int WIDTH = 120;		// Standart console Width
	const int ITERATIONS = 32;	// Iterations per pixel

	float aspect = (float)WIDTH / HEIGHT;
	float pixelaspect = 11.0f / 22;

	char pixel = ' ';			// Symbol for drawing the fractal

	// Drawing loops
	for (int i = 0; i < HEIGHT; i++)	// Main for loop, using for drawing endlines 
	{
		for (int j = 0; j < WIDTH; j++)	// Second main for loop, using for drawing rows
		{
			double Re = (double)j / WIDTH * 2.0f - 1.0f;	// Translate coordinates for Real Numbers
			double Im = (double)i / HEIGHT * 2.0f - 1.0f;	// Translate coordinates for Imagined Numbers
			Re *= aspect * pixelaspect;						// Fix for width in command line		

			complex<double> Zn(0, 0);
			complex<double> Complex(Re, Im);
			for (int n = 0; n < ITERATIONS; n++)
			{
				Zn = pow(Zn, 2) + Complex;					// Mandelbrot set calculating for every pixel

				if (abs(Zn) < 4) {
					pixel = '$';		
				}
				else {
					pixel = ' ';
				}
			}
			cout << pixel;
		}
		cout << endl;
	}
	return 0;
}