#include "Mandelbrot.h"
#include <complex>
namespace fractals
{

    Mandelbrot::Mandelbrot()
    {
    }


    Mandelbrot::~Mandelbrot()
    {
    }

    int Mandelbrot::getIterations(double x, double y)
    {
        std::complex<double> z = 0;
        std::complex<double> c(x, y);

        int iterations = 0;
        /*
        Mandlebrot set is from -2, 2. Entire plot fits
        withint a circle of diameter 2 centered around
        the origin of the plot 
        */
        while (iterations < MAX_ITERATIONS)
        {
            z = z * z + c;

            if (abs(z) > 2) break;

            iterations++;
        }
        return iterations;
    }
}