#pragma once
#include <string>
#include <memory>
#include <limits>
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Functions.h"

class FractalCreator
{
private:
    unsigned int _width{ 0 };
    unsigned int _height{ 0 };
    unsigned int _sum{ 0 };

    std::unique_ptr<int[]> _histogram;
    std::unique_ptr<int[]> _fractal;

    bitmap::Bitmap _bitmap;
    fractals::ZoomList _zoomlist;

public:
    FractalCreator(int width, int height);

    void calculateIteration();
    void calculateTotalIterations();
    void drawFractral();
    void addZoom(const fractals::Zoom& zoom);
    void writeBitmap(std::string name);

    virtual ~FractalCreator();
};

