#pragma once
#include <cstdint> // for filesize. To ensure it is 32 bit

#pragma pack(2)
//need to pack the BitmapFileHead with only 2 byte boundaries to
//avoid extra padding. Otherwise the extra padding will make bitmap
//unreadable

namespace bitmap
{

    struct BitmapFileHeader
    {
        char header[2]{'B','M'};
        int32_t fileSize;
        int32_t reserved{0};
        int32_t dataOffset;     //how long into the file the data begins
    };

}