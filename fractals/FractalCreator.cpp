#include "FractalCreator.h"

FractalCreator::FractalCreator(int width, int height) :
    _width(width), _height(height),
    _histogram(new int[fractals::Mandelbrot::MAX_ITERATIONS + 1]{ 0 }),
    _fractal(new double[_width*_height]),
    _bitmap(_width, _height, "test.bmp"),
    _zoomlist(_width, _height)
{
    _zoomlist.add(fractals::Zoom(_width/2, _height/2 , 4.0/_width));
}

void FractalCreator::calculateIteration()
{
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
        {
            std::pair<double, double> coords = _zoomlist.doZoom(x, y);

            double iterations = fractals::Mandelbrot::getJulia(coords.first, coords.second, -0.4, 0.6);

            _fractal[y*_width + x] = abs(iterations);

            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS) _histogram[floor(iterations)]++;

        }
}

void FractalCreator::drawFractral()
{
    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS + 1; i++)
    {
        //std::cout << _histogram[i] << std::endl;
    }
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++)
        {
            RGB rgb(0, 0, 0);

            double iterations = _fractal[y*_width + x];

            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += _histogram[i] / static_cast<double>(_sum);
                }

                double color = 360.0*iterations/fractals::Mandelbrot::MAX_ITERATIONS;
                HSV hsv(color, 1.0, 1.0);

                rgb = toRGB(hsv);
            }
            _bitmap.setPixel(x, y, rgb._r, rgb._g, rgb._b);
            
        }
    }
}
void FractalCreator::addZoom(const fractals::Zoom& zoom)
{
    _zoomlist.add(zoom);
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
    {
        _sum += _histogram[i];
    }
}

void FractalCreator::writeBitmap(std::string name) 
{
    _bitmap.write(name);
}

FractalCreator::~FractalCreator() {}