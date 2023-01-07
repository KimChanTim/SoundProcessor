#include "converter.h"

MixConverter::MixConverter(std::string& str, int start) : start(start * FREQUENCY) {
    second_channel = new WAV_channel(str);
}

MixConverter::~MixConverter() {
    delete second_channel;
}

void MuteConverter::apply(WAV_channel& input_channel) {
    int count_of_read = input_channel.Get_count();
    for (int i = 0; i < count_of_read; i++) {
        if (time_cnt >= start && time_cnt < stop) {
            input_channel.buf[i] = 0;
        }
        time_cnt++;
    }
}

void MixConverter::apply(WAV_channel& input_channel) {
    bool second_is_end = false;
    if (!second_channel->isEnd())
        second_channel->read();
    else
        second_is_end = true;

    int count_of_read = input_channel.Get_count();
    int count_of_read2 = second_channel->Get_count();

    for (int i = 0; i < count_of_read; i++) {
        if ((time_cnt > start) && (!second_is_end) && (i < count_of_read2)) {
            input_channel.buf[i] = (short int)((input_channel.buf[i] + second_channel->buf[i]) / 2);
        }
        time_cnt++;
    }
}

void NoiseConverter::apply(WAV_channel& input_channel) {
    int count_of_read = input_channel.Get_count();
    for (int i = 0; i < count_of_read; i++) {
        if (time_cnt >= start && time_cnt < stop) {
            if ((rand() % width) == 1)
                input_channel.buf[i] = (short int)(input_channel.buf[i] + (rand() % depth));
        }
        time_cnt++;
    }
}
