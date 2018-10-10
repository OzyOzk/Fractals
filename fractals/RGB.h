#pragma once
#include <cstdint>

struct RGB
{
    uint8_t _r{ 0 };
    uint8_t _g{ 0 };
    uint8_t _b{ 0 };

    RGB(uint8_t r, uint8_t g, uint8_t b) : _r(r), _g(g), _b(b) {}
};


