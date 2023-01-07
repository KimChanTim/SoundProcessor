#ifndef SOUNDPROCESSOR_WAV_CHANNEL_H
#define SOUNDPROCESSOR_WAV_CHANNEL_H

#pragma once

#include <iostream>
#include <string>
#include <fstream>

#define BUFSIZE 1024
#define HEADERSIZE 44
#define FREQUENCY 44100

class WAV_channel {
    std::ifstream input_file;
    std::ofstream output_file;

    char header[HEADERSIZE];
    int count_of_read;

public:
    short int buf[BUFSIZE];

    WAV_channel() = delete;
    WAV_channel(const std::string&);
    WAV_channel(const std::string&, const std::string&);
    ~WAV_channel();

    void read();
    void write();
    int Get_count();
    bool isEnd();
};

#endif //SOUNDPROCESSOR_WAV_CHANNEL_H
