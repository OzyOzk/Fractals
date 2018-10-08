#include <iostream>


#include "FractalCreator.h"

//hello
int main()
{
    int height = 600;

    FractalCreator fractalcreator(800, 600);

    fractalcreator.addZoom(fractals::Zoom(295, height - 202, 0.1));
    fractalcreator.addZoom(fractals::Zoom(312, height - 304, 0.1));
    fractalcreator.calculateIteration();
    fractalcreator.calculateTotalIterations();
    fractalcreator.drawFractral();
    fractalcreator.writeBitmap("test1.bmp");
    std::cout << "finished" << std::endl;
}

/*

//Test code for seting entire map a flat colour

    for(int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
        {
            bitmap.setPixel(x, y, 255, 0, 255);
        }

*/


/*

//Test code for seeing iterations and validating histogram;

    int sum = 0;
    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
    {
        std::cout << "index " << i << ":\t" << histogram[i] << std::endl;
        sum += histogram[i];
    }
    
    std::cout << "Histogram sum\t" << sum << std::endl;
    std::cout << "Maximum pixles\t " << HEIGHT * WIDTH << std::endl;

*/