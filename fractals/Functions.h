#pragma once
#include <math.h>
#include <cstdint>

#include "HSV.h"
#include "RGB.h"

RGB toRGB(HSV& hsv);

double linearIterpolation(double x1, double x2, double c);