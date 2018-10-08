#include <iostream>
#include "RGB.h"

#include "FractalCreator.h"

int main()
{
    FractalCreator fractalcreator(2160, 1440);
    fractalcreator.addRange(1.0, RGB(0, 0, 0));
    /*
    fractalcreator.addRange(0.0, RGB(0, 0, 0));
    fractalcreator.addRange(0.1, RGB(255, 0, 0));
    fractalcreator.addRange(0.2, RGB(255, 128, 0));
    fractalcreator.addRange(0.3, RGB(204, 204, 0));
    fractalcreator.addRange(0.4, RGB(102, 204, 0));
    fractalcreator.addRange(0.5, RGB(0, 204, 0));
    fractalcreator.addRange(0.6, RGB(0, 204, 102));
    fractalcreator.addRange(0.7, RGB(0, 204, 204));
    fractalcreator.addRange(0.8, RGB(255, 102, 204));
    fractalcreator.addRange(0.9, RGB(0, 0, 204));
    fractalcreator.addRange(1.0, RGB(102, 0, 204));
    */
    //fractalcreator.addZoom(fractals::Zoom(295, 202, 0.1));
    //fractalcreator.addZoom(fractals::Zoom(312, 304, 0.1));
    fractalcreator.run("test1.bmp");

    std::cout << "finished" << std::endl;
}

