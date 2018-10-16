#include <iostream>

#include "FractalCreator.h"
#include "Log.h"

int test_w = 1920;
int test_h = 1080;

std::string name = "Test4.bmp";

//  with_hsv


int main()
{
    Log log(name, 480, 320);

    FractalCreator fractalcreator(test_w, test_h);
    /*
    fractalcreator.addZoom(fractals::Zoom(2560, height_8k - 1288, 0.1));
    fractalcreator.addZoom(fractals::Zoom(3180, height_8k - 1840, 0.1));
    fractalcreator.addZoom(fractals::Zoom(3840, height_8k - 2152, 0.05));
    fractalcreator.addZoom(fractals::Zoom(3896, height_8k - 2228, 0.005));
    */
    fractalcreator.calculateIteration();
    fractalcreator.calculateTotalIterations();
    fractalcreator.drawFractral();
    fractalcreator.writeBitmap(name);
    std::cout << "finished" << std::endl;
    std::cin.get();
}

