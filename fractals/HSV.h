#pragma once

struct HSV
{
    double _h{ 0 };
    double _s{ 0 };
    double _v{ 0 };

    bool operator==(const HSV& other)
    {
        return ((_h == other._h) && (_s == other._s) && (_v == other._v));
    }
};