#ifndef SOUNDPROCESSOR_STATE_H
#define SOUNDPROCESSOR_STATE_H

#pragma once

#include <iostream>
#include <vector>

class InState {
public:
    std::string output;
    std::string config;
    std::vector<std::string> input;
};

#endif //SOUNDPROCESSOR_STATE_H
