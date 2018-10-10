#include "Mandelbrot.h"
#include <complex>
#include <math.h>
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
        std::complex<double> zn = 0;
        std::complex<double> c(x, y);

        int iterations = 0;
        //double smooth = 0.0;
        /*
        Mandlebrot set is from -2, 2. Entire plot fits
        withint a circle of diameter 2 centered around
        the origin of the plot 
        */
        while (iterations < MAX_ITERATIONS)
        {
            z = z * z + c;

            if (abs(z) > 2)
            {
                //zn = z;
                break;
            }
            iterations++;
        }
        
        //smooth = iterations - log(log(abs(zn)) / log(360.0)) / log(2);
        return iterations;
    }
}