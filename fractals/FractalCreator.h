#pragma once

#include "Zoom.h"
#include <string>

class FractalCreator
{
public:
    FractalCreator();

    void calculatedIteration();
    void drawFractral();
    void addZoom(const fractals::Zoom& zoom);
    void writeBitmap(std::string name);

    virtual ~FractalCreator();
};

