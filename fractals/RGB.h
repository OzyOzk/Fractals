#pragma once
class RGB
{
 public:
    double _r{ 0 };
    double _g{ 0 };
    double _b{ 0 };
public:
    RGB(double r, double g, double b);

    friend RGB operator-(const RGB& first, const RGB& second);
};

