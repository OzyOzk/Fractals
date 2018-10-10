#include "Log.h"

Log::Log(const std::string& filename, int width, int height): _filename(filename), _width(width), _height(height)
{
    _filename = _filename.substr(0, _filename.length() - 3) += "txt";
    t1 = std::chrono::steady_clock::now();
}

Log::~Log()
{
    t2 = std::chrono::steady_clock::now();
    duration = (t2 - t1);
    _file.open(_filename);

    _file << "Filename:\t\t\t"  << "bmp" << "\n";
    _file << "Height:\t\t\t\t" << _height << "\n";
    _file << "Width:\t\t\t\t" << _width << "\n";
    _file << "Duration(seconds):\t\t" << duration.count() << "\n";
    #ifdef _DEBUG
    _file << "Build mode:\t\tDebug\n";
    #else
    _file << "Build mode:\t\t\tRelease\n";
    #endif
}
