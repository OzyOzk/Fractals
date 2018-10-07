#include <iostream>
#include <limits>
#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "Log.h"
#include "ZoomList.h"

//
int main()
{
    int const WIDTH = 2560;
    int const HEIGHT = 1440;

    bitmap::Bitmap bitmap(WIDTH, HEIGHT, "test.bmp");
    Log mylog(bitmap, WIDTH, HEIGHT);

    double min = std::numeric_limits<double>::max();
    double max = std::numeric_limits<double>::min();

    fractals::ZoomList zoomlist(WIDTH, HEIGHT);

    zoomlist.add(fractals::Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    //zoomlist.add(fractals::Zoom(295, HEIGHT - 300, 0.7 ));
    //zoomlist.add(fractals::Zoom(312, HEIGHT - 304, 0.1));


    std::unique_ptr<int[]> histogram(new int[fractals::Mandelbrot::MAX_ITERATIONS + 1]{0}); //curly brackers initialize to 0
    std::unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]);

    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
        {
            std::pair<double, double> coords = zoomlist.doZoom(x, y);

            int iterations = fractals::Mandelbrot::getIterations(coords.first, coords.second);

            fractal[y*WIDTH + x] = iterations;

            if(iterations != fractals::Mandelbrot::MAX_ITERATIONS) histogram[iterations]++;
            
        }
    
    int sum = 0;

    for (int i = 0; i < fractals::Mandelbrot::MAX_ITERATIONS; i++)
    {
        sum += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++)
        {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            int iterations = fractal[y*WIDTH + x];
            if (iterations != fractals::Mandelbrot::MAX_ITERATIONS)
            {
                double hue = 0.0;

                for (int i = 0; i <= iterations; i++)
                {
                    hue += static_cast<double>(histogram[i]) / sum;
                }

                red = 0;
                green = pow(255, hue);
                blue = 0;
            }

            bitmap.setPixel(x, y, red, green, blue);

        }
    }

    bitmap.write("test.bmp");
    std::cout << "finished" << std::endl;
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