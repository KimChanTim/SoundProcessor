#include "WAV_channel.h"

WAV_channel::WAV_channel(const std::string& in_str) {
    input_file.open(in_str, std::ios::binary);
    if (input_file.fail())
        throw std::invalid_argument("Invalid input file.");

    input_file.read(reinterpret_cast<char*>(header), HEADERSIZE);
}

WAV_channel::WAV_channel(const std::string& in_str, const std::string& out_str) {
    input_file.open(in_str, std::ios::binary);
    if (input_file.fail())
        throw std::invalid_argument("Invalid input file.");

    output_file.open(out_str, std::ios::binary);
    if (output_file.fail())
        throw std::invalid_argument("Invalid output file.");

    input_file.read(reinterpret_cast<char*>(header), HEADERSIZE);
    output_file.write(reinterpret_cast<char*>(header), HEADERSIZE);
}

WAV_channel::~WAV_channel() {
    input_file.close();
    if (output_file.is_open())
        output_file.close();
}

void WAV_channel::read() {
    input_file.read(reinterpret_cast<char*>(buf), BUFSIZE);
    count_of_read = input_file.gcount();
}

void WAV_channel::write() {
    if (output_file.is_open())
        output_file.write(reinterpret_cast<char*>(buf), count_of_read);
}

int WAV_channel::Get_count() {
    return count_of_read;
}

bool WAV_channel::isEnd() {
    if (input_file.eof())
        return true;
    return false;
}
