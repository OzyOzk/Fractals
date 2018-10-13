# Fractals

### Tasks

* Large images are taking a while to generate (8K image at 10000 iterations took 20 minutes). Need to look into optimization
* Need to add color smoothing. There is very noticable banding. Need to implement logarithmic smoothing to mandlebrot function

#### Color Smoothing

Added Color smoothing by normalizing the iteration count. Done by taking the log of the log of the magnitude of the imagninary number at escape value. See below;

```cpp
if(abs(z) > 2)
{
  return iterations + 1.0 - log(log2(abs(z)));
  break;
}
```

This produces images like those below;
![Smooth mandelbrot](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/smooth1j.jpg)
![Smooth mandelbrot zoomed](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/smooth2j.jpg)

The problem now is that as the lower iteration count complex numbers are colored in a very limited range of the color spectrum (Mostly red). This problem gets worse as you increase the maximum iteration count. I will combine the normalized iteration count with the histogram method to spread out the color range. Once done code will be posted with further samples

### Sample images
These images are genearated using the code found in the "with_hsv" branch of this project. All samples are .jpeg as the generated bitmaps are huge.



Hue[0,60], saturation 100%, value 100%
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/main.jpg)

Wide RGB range in zoomed in region

![Zoomed in colourful](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test10j.jpg)

Hue[220,260], saturation 100%, value 100%. Gradually zooming in
![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test4j.jpg)

![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test5j.jpg)

![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test6j.jpg)

![Large 8K image using limited hue region](https://github.com/OzyOzk/fractals/blob/with_hsv/fractals/Samples/Test7j.jpg)


