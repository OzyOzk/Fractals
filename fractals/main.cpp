#include <iostream>

#include "FractalCreator.h"
#include "Log.h"

int width_4k = 3840;
int height_4k = 2160;

int width_2k = 2560;
int height_2k = 1440;

int width_8k = 7680;
int height_8k = 4320;

int width_fhd = 1080;
int height_fhd = 720;

int test_w = 800;
int test_h = 600;

std::string name = "Test4.bmp";




int main()
{
    Log log(name, width_8k, height_8k);

    FractalCreator fractalcreator(width_8k, height_8k);

    fractalcreator.addZoom(fractals::Zoom(2560, height_8k - 1288, 0.1));
    fractalcreator.addZoom(fractals::Zoom(3180, height_8k - 1840, 0.1));
    fractalcreator.addZoom(fractals::Zoom(3840, height_8k - 2152, 0.05));
    fractalcreator.addZoom(fractals::Zoom(3896, height_8k - 2228, 0.005));
    fractalcreator.calculateIteration();
    fractalcreator.calculateTotalIterations();
    fractalcreator.drawFractral();
    fractalcreator.writeBitmap(name);
    std::cout << "finished" << std::endl;
}

