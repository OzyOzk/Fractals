#include "Mandelbrot.h"
#include <complex>
#include <math.h>
namespace fractals
{
    Mandelbrot::Mandelbrot() {}
    Mandelbrot::~Mandelbrot() {}

    double Mandelbrot::getMandelbrot(double x, double y)
    {
        std::complex<double> c(x, y);
        std::complex<double> z = 0;

        double iterations = 0;

        while (iterations <= MAX_ITERATIONS)
        {
            z = z * z + c;

            if (abs(z) > ESCAPE_RADIUS)
            {
                return iterations + 1.0 - log(log(abs(z))) / log(ESCAPE_RADIUS);
            }
            iterations++;
        }
        return static_cast<double>(MAX_ITERATIONS);
    }

    double Mandelbrot::getJulia(double x, double y, double c1, double c2)
    {
        std::complex<double> z(x, y);
        std::complex<double> c(c1, c2);

        double iterations = 0;

        while (iterations < MAX_ITERATIONS)
        {
            z = z * z + c;
            if (abs(z) > ESCAPE_RADIUS) {
                return iterations + 1.0 - log(log(abs(z)))/log(ESCAPE_RADIUS);
                break;
            }
            iterations++;
        }
        return double(MAX_ITERATIONS);
    }

}