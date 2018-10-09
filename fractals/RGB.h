#pragma once

struct RGB
{
    double _r{ 0 };
    double _g{ 0 };
    double _b{ 0 };

    RGB(double r, double g, double b);
};

RGB::RGB(double r, double g, double b) : _r(r), _g(g), _b(b) {}


RGB operator-(const RGB& first, const RGB& second)
{
    return RGB(first._r - second._r, first._g - second._g, first._b - second._b);
}