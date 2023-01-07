#include "parser.h"
#include <sstream>

parser::parser(InState& state) : input(state.input), output(state.output) {
    config_stream.open(state.config);
    if (config_stream.fail())
        throw std::invalid_argument("Invalid config file.");
}

parser::~parser() {
    config_stream.close();
}

void parser::apply(std::vector<Converter*>& converter_vector) {
    try {
        std::string str;
        std::string string;
        while (std::getline(config_stream, str)) {
            std::stringstream str_stream(str);
            std::string word;
            str_stream >> word;
            if (word == "#") {
                continue;
            }
            if (word == "mute") {
                str_stream >> word;
                int start = stoi(word);
                str_stream >> word;

                Converter* mute_converter = new MuteConverter(start, stoi(word));
                converter_vector.push_back(mute_converter);
                continue;
            }
            if (word == "mix") {
                std::string second_file;
                str_stream >> second_file;
                str_stream >> word;
                if (second_file[0] == '$') {
                    second_file.erase(0, 1);
                    second_file = input[stoi(second_file)];
                }

                Converter* mix_converter = new MixConverter(second_file, stoi(word));
                converter_vector.push_back(mix_converter);
                continue;
            }
            if (word == "noise") {
                str_stream >> word;
                int start = stoi(word);
                str_stream >> word;
                int stop = stoi(word);
                str_stream >> word;
                int width = stoi(word);
                str_stream >> word;

                Converter* noise_converter = new NoiseConverter(start, stop, width, stoi(word));
                converter_vector.push_back(noise_converter);
                continue;
            }
            throw std::invalid_argument("The config file is not correct.");
        }
    } catch(std::invalid_argument& ex) {
        throw ex;
    } catch(...) {
        std::cerr << "Unknown error." << std::endl;
    }
}
