#include "FractalCreator.h"

FractalCreator::FractalCreator(int width, int height) :
    _width(width), _height(height),
    _histogram(new int[fractals::Mandelbrot::MAX_ITERATIONS + 1]{ 0 }),
    _fractal(new int[_width*_height]),
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

            int iterations = fractals::Mandelbrot::getIterations(coords.first, coords.second);

            _fractal[y*_width + x] = iterations;

            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS) _histogram[iterations]++;

        }
}

void FractalCreator::drawFractral()
{
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++)
        {

            RGB rgb(0, 0, 0);

            int iterations = _fractal[y*_width + x];

            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += static_cast<double>(_histogram[i]) / _sum;
                }

                //hue = 200+hue * 50;
                int h = pow(40, hue);
                HSV hsv(220.0+h, 0.8, 0.8);

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

FractalCreator::~FractalCreator()
{
}

/*

            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += static_cast<double>(_histogram[i]) / _sum;
                }

                //hue = 200+hue * 50;
                
                HSV hsv(0, 0.9, hue);

                rgb = toRGB(hsv);
            }

*/