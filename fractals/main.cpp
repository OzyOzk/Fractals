#include <iostream>

#include "FractalCreator.h"
#include "Log.h"

int width_4k = 3840;
int height_4k = 2160;

int width_2k = 2560;
int height_2k = 1440;

int width_8k = 7680;
int height_8k = 4320;

std::string name = "Test4.bmp";



int main()
{
    Log log(name, width_4k, height_4k);

    FractalCreator fractalcreator(width_4k, height_4k);


    fractalcreator.calculateIteration();
    fractalcreator.calculateTotalIterations();
    fractalcreator.drawFractral();
    fractalcreator.writeBitmap(name);
    std::cout << "finished" << std::endl;
}

