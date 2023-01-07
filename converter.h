#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H

#pragma once

#include "WAV_channel.h"
#include <string>
#include <utility>

class Converter {
protected:
    int time_cnt = 0;

public:
    virtual void apply(WAV_channel&) = 0;
};

class MuteConverter : public Converter {
    int start;
    int stop;

public:
    MuteConverter(int start, int stop) : start(start * FREQUENCY), stop(stop * FREQUENCY) {};
    void apply(WAV_channel&) override;
};

class MixConverter : public Converter {
    int start;
    WAV_channel* second_channel;

public:
    MixConverter(std::string&, int);
    ~MixConverter();
    void apply(WAV_channel&) override;
};

class NoiseConverter : public Converter {
    int start;
    int stop;
    int width;
    int depth;

public:
    NoiseConverter(int start, int stop, int width, int depth) : start(start * FREQUENCY), stop(stop * FREQUENCY), width(width), depth(depth) {};
    void apply(WAV_channel&) override;
};

#endif //SOUNDPROCESSOR_CONVERTER_H
