//
// Created by user on 11/11/23.
//

#include "lib.h"
#include <iostream>

using std::cout;

int process(const char* input, const unsigned int input_size, const char* output, const unsigned int output_size,
            const char* value, const unsigned int value_size,
            const char* start, const unsigned int start_size, const char* end, const unsigned int end_size) {
    cout << "input=" << input << " output=" << output << " value=" << value << " start=" << start << " end=" << end <<
            "\n";
    return 0;
}
