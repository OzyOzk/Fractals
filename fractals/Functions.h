#pragma once
#include "HSV.h"
#include "RGB.h"
#include <math.h>
#include <cstdint>

RGB toRGB(HSV& hsv)
{
    int r = 0;
    int g = 0;
    int b = 0;

    uint8_t R = 0;
    uint8_t G = 0;
    uint8_t B = 0;

    if (hsv._h == 0)
    {
        r = hsv._v;
        g = hsv._v;
        b = hsv._v;
    }
    else
    {
        int i;
        double f, p, q, t;

        if (hsv._h == 360) hsv._h = 0;

        else hsv._h = hsv._h / 60;

        i = static_cast<int> (trunc(hsv._h));
        f = hsv._h - 1;

        p = hsv._v * (1.0 - hsv._s);
        q = hsv._v * (1.0 - (hsv._s * f));
        t = hsv._v * (1.0 - (hsv._s * (1.0 - f)));

        if (i == 0) { r = hsv._v; g = t; b = p; }

        else if (i == 1) { r = q; g = hsv._v; b = p; }

        else if (i == 2) { r = p; g = hsv._v; b = t; }

        else if (i == 3) { r = p; g = q; b = hsv._v; }

        else if (i == 4) { r = t; g = p; b = hsv._v; }

        else if (i == 5) { r = hsv._v; g = p; b = q; }

        else { r = hsv._v; g = p; b = q; }
    }

    R = r * 255;
    G = g * 255;
    B = B * 255;

    return RGB(R, G, B);
}