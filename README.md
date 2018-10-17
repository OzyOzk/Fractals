# Fractals

### Tasks

* Large images are taking a while to generate (8K image at 10000 iterations took 20 minutes). Need to look into optimization
* ~~Need to add color smoothing. There is very noticable banding. Need to implement logarithmic smoothing to mandlebrot function~~

#### Color Smoothing

Added Color smoothing by normalizing the iteration count. Done by taking the log of the log of the magnitude of the imagninary number at escape value. See below;

```cpp
if(abs(z) > 2)
{
  return iterations + 1.0 - log(log2(abs(z)));
  break;
}
```
**The normalized iteration count is now calculated as follows;**
```cpp
return iterations + 1.0 - log(log(abs(z))) / log(ESCAPE_RADIUS);
```
This is more generalized as I may choose to increase the escape radius (bailout radius to some) later.

This produces images like those below;
50 iterations to produce the image below.
![Smooth mandelbrot](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/smooth1j.jpg)
Zoomed in regions shown below need a higher iteration count 
![Smooth mandelbrot zoomed](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/smooth2j.jpg)

#### Estimating distance to nearest mandelbrot surface

I'll be adding in the ability to draw the mandelbrot set using a distance estimation algorithm. Currently I have the following;

```cpp
double Mandelbrot::getIterations(double x, double y)
{
    complex<double> c(x, y);
    complex<double> z = 0;
    complex<double> dz = 0;

    double iterations = 0;

    while (iterations < MAX_ITERATIONS)
    {
        dz = 2.0 * dz * z + 1.0;
        z = z * z + c;

        if (abs(z) > 10000)
        {
            return abs(abs(z) * log(abs(z)) / abs(dz));
        }
        iterations++;
    }
    return 0;
}
```
This produces a blurred plot but this can be alleviated using a large bailout radius and also more iterations

#### Julia sets

Also working on implementing julia set generation. Currently have the following;
```cpp
double Mandelbrot::getJulia(double x, double y)
{
    complex<double> z(x,y);
    complex<double> c(-0.7269, 0.1889);

    double iterations = 0;

    while (iterations < MAX_ITERATIONS)
    {
        z = z * z + c;
        if (abs(z) > 2) {
            return iterations + 1.0 - log(log2(abs(z)));
            break;
        }
        iterations++;
    }
    return double(MAX_ITERATIONS);
}
```
And also the distance estimation

```cpp
double Mandelbrot::getIterations(double x, double y)
{
  complex<double> c(x, y);
  complex<double> z = 0;
  complex<double> dz = 0;

  double iterations = 0;

  while(iterations < MAX_ITERATIONS)
  {
      dz = 2.0 * dz * z + 1.0;
      z = z * z + c;

      if(abs(z) > 2)
      {
        break;
      }
      iterations++;
  }
  return 0.5*log(abs(z)*abs(z)/abs(dz);
}
```
### Sample images
These images are genearated using the frequence of the number of iteration e.g. if at pixle  x,y it took n iterations, and the total
number of pixels with n iterations is m, normalize m and use taht to color in the plot.


Hue[0,60], saturation 100%, value 100%
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/main.jpg)

Wide RGB range in zoomed in region Hue[0,360], saturation 100%, value 100%

![Zoomed in colourful](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test10j.jpg)

Hue[220,260], saturation 100%, value 100%. Gradually zooming in
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test4j.jpg)
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test5j.jpg)
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test6j.jpg)
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test7j.jpg)


