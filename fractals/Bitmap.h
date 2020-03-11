#pragma once

#include <string>
#include <cstdint>
#include <memory>

namespace bitmap
{
    class Bitmap
    {
    private:
        int _width{ 0 };
        int _height{ 0 };
        std::string _name;
        std::unique_ptr<uint8_t[]> _pPixels{ nullptr };

    public:
        Bitmap(int width, int height, std::string name);
       // Bitmap() = default;
        bool write(std::string filename);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        virtual ~Bitmap();

        std::string getname() const;

    };
}
