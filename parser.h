#ifndef SOUNDPROCESSOR_PARSER_H
#define SOUNDPROCESSOR_PARSER_H

#pragma once

#include "state.h"
#include "converter.h"
#include <fstream>
#include <vector>


class parser {
    std::string output;
    std::vector<std::string> input;

    std::ifstream config_stream;

public:
    parser(InState&);
    ~parser();

    void apply(std::vector<Converter*>&);
};

#endif //SOUNDPROCESSOR_PARSER_H
