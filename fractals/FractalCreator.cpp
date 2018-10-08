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

void FractalCreator::run(std::string name)
{
    calculateIteration();
    calculateTotalIterations();
    calculateRangeTotals();
    drawFractral();
    writeBitmap(name);
}

void FractalCreator::addRange(double rangeEnd, const RGB& rgb)
{
    _ranges.push_back(rangeEnd * fractals::Mandelbrot::MAX_ITERATIONS);
    _colors.push_back(rgb);

    if (_bGotFirstRange)
    {
        _rangeSums.push_back(0);
    }

    _bGotFirstRange = true;
}

int FractalCreator::getRange(int iterations) const
{
    int range = 0;

    for (int i = 1; i < _ranges.size(); i++)
    {
        range = i;

        if (_ranges[i] > iterations)
        {
            break;
        }
    }

    range--;

    assert(range > -1);
    assert(range < _ranges.size()); 
    return range;
}

void FractalCreator::addZoom(const fractals::Zoom& zoom)
{
    _zoomlist.add(zoom);
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


void FractalCreator::calculateRangeTotals()
{
    int rangeIndex = 0;

    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
    {
        int pixels = _histogram[i];
        if (i >= _ranges[rangeIndex + 1]) rangeIndex++;
        _rangeSums[rangeIndex] += pixels;
    }

    /*
    for (int value : _rangeSums)
    {
        std::cout << "Range total: " << value << std::endl;
    }
    */
}

void FractalCreator::calculateTotalIterations()
{
    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
    {
        _sum += _histogram[i];
    }
}

void FractalCreator::drawFractral()
{

    RGB startColor(0, 0, 0);
    RGB endColor(0,0,255);
    RGB colorDif = endColor - startColor;

    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++)
        {
            int iterations = _fractal[y*_width + x];

            int range = getRange(iterations);
            int rangeTotal = _rangeSums[range];
            int rangeStart = _ranges[range];

            RGB& startColor = _colors[range];
            RGB& endColor = _colors[range + 1];
            RGB colorDif = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;


            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS)
            {
                int totalPixels = 0;

                for (int i = rangeStart; i <= iterations; i++)
                {
                    totalPixels += _histogram[i];
                }

                red = startColor._r + colorDif._r * (double)totalPixels / rangeTotal;
                green = startColor._g + colorDif._g * (double)totalPixels / rangeTotal;
                blue = startColor._b + colorDif._b * (double)totalPixels / rangeTotal;
            }

            _bitmap.setPixel(x, y, red, green, blue);

        }
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

//Test code for seting entire map a flat colour

for(int y = 0; y < HEIGHT; y++)
for (int x = 0; x < WIDTH; x++)
{
bitmap.setPixel(x, y, 255, 0, 255);
}

*/


/*

//Test code for seeing iterations and validating histogram;

int sum = 0;
for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
{
std::cout << "index " << i << ":\t" << histogram[i] << std::endl;
sum += histogram[i];
}

std::cout << "Histogram sum\t" << sum << std::endl;
std::cout << "Maximum pixles\t " << HEIGHT * WIDTH << std::endl;

*/