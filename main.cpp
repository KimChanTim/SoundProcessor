#include "state.h"
#include "editor.h"
#include <iostream>
#include <cstring>
#include <ctime>

InState readState(int argc, char **argv) {
    InState state;
    bool out_found = false;
    for (int i = 1; i < argc; i++) {
        try {
            if (!strcmp(argv[i], "-h")) {
                std::cout << "sound_processor [-h] [-c config.txt output.wav input1.wav [input2.wav …]]" << std::endl;
                exit(0);
            }
            if (!strcmp(argv[i], "-c")) {
                i++;
                if (i == argc) {
                    throw std::out_of_range("The config file name is absent.");
                } else {
                    state.config = argv[i];
                }
                continue;
            }
            if (!out_found) {
                state.output = argv[i];
                out_found = true;
                continue;
            }
            state.input.emplace_back(argv[i]);
        } catch (std::out_of_range& ex) {
            std::cerr << ex.what() << std::endl;
        } catch (...) {
            std::cerr << "Unknown error." << std::endl;
        }
    }
    return state;
}

int main(int argc, char **argv) {
    try {
        srand(time(nullptr));
        InState state = readState(argc, argv);
        sound_edit(state);
    }
      catch(std::invalid_argument& ex) {
        std::cerr << ex.what() << std::endl;
    } catch(...) {
        std::cerr << "Unknown error." << std::endl;
    }
    return 0;
}
