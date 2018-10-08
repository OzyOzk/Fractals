#pragma once
#include <string>
#include <memory>
#include <limits>
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>
#include <vector>
#include <assert.h>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Log.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "RGB.h"
 

class FractalCreator
{
private:
    int _width{ 0 };
    int _height{ 0 };
    int _sum{ 0 };

    std::unique_ptr<int[]> _histogram;
    std::unique_ptr<int[]> _fractal;

    std::vector<int> _ranges;
    std::vector<RGB> _colors;
    std::vector<int> _rangeSums;

    bool _bGotFirstRange{ false };

    bitmap::Bitmap _bitmap;
    fractals::ZoomList _zoomlist;

private:

    void calculateIteration();
    void calculateTotalIterations();
    void drawFractral();
    void calculateRangeTotals();
    void writeBitmap(std::string name);
    int getRange(int iterations) const;

public:
    FractalCreator(int width, int height);
    void addRange(double rangeEnd, const RGB& rgb);
    void run(std::string);
    void addZoom(const fractals::Zoom& zoom);

    virtual ~FractalCreator();
};

