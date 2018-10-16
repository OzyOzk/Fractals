#pragma once

namespace fractals
{
    class Mandelbrot
    {
    public:
        static const int MAX_ITERATIONS = 100;
        static const int ESCAPE_RADIUS = 2;
    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static double getIterations(double x, double y);
    };
}
