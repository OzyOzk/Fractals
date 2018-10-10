#pragma once

struct HSV
{
    double _h{ 0 };
    double _s{ 0 };
    double _v{ 0 };

    HSV(double h, double s, double v) : _h{ h }, _s{ s }, _v{ v } {}

    HSV() : _h{ 0 }, _s{ 0 }, _v{ 0 } {}

    bool operator==(const HSV& other)
    {
        return ((_h == other._h) && (_s == other._s) && (_v == other._v));
    }
};