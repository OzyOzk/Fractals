#pragma once

#include <chrono>
#include <fstream>
#include <iostream>

class Log
{
public:
    Log() = delete;
    Log(Log& other) = delete;
    Log(const std::string& filename, int width, int height);
    virtual ~Log();
private:
    std::chrono::time_point<std::chrono::steady_clock> t1, t2;
    std::chrono::duration<double> duration;
    std::ofstream _file;
    std::string _filename;
    unsigned int _height{0};
    unsigned int _width{0};
};

