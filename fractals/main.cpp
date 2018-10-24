#include <iostream>

#include "FractalCreator.h"
#include "Log.h"

int test_w = 7680;  //  7680    4096    2560    1920    1280
int test_h = 4320;  //  4320    2160    1440    1080    720

std::string name = "8k_julia_rgb_n0d4p0dt.bmp";

//  with_hsv


int main()
{
    Log log(name, test_w, test_h);

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
    //std::cin.get();
}

