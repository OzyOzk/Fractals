#include "Functions.h"

RGB toRGB(HSV& hsv)
{
    double r = 0;
    double g = 0;
    double b = 0;

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

        if (hsv._h == 360.0) hsv._h = 0;

        else hsv._h = hsv._h / 60.0;

        i = static_cast<int> (floor(hsv._h));
        f = hsv._h - i;

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

    R = static_cast<uint8_t>(r * 255);
    G = static_cast<uint8_t>(g * 255);
    B = static_cast<uint8_t>(b * 255);

    return RGB(R, G, B);
}