#include "editor.h"
#include "converter.h"
#include "WAV_channel.h"
#include <vector>

void sound_edit(InState& state) {
    parser config_parser(state);
    std::vector<Converter*> converter_vector;
    config_parser.apply(converter_vector);

    WAV_channel input_channel(state.input[0], state.output);

    while (!input_channel.isEnd()) {
        input_channel.read();
        for (auto & it : converter_vector) {
            it->apply(input_channel);
        }
        input_channel.write();
    }
}
