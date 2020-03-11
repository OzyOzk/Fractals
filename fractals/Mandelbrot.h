#pragma once

namespace fractals
{
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS{ 256 };
        static const int ESCAPE_RADIUS{ 20000000 };
    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static double getMandelbrot(double x, double y);
        static double getJulia(double x, double y, double c1, double c2);
    };
}
