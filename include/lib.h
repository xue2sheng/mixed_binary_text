//
// Created by user on 11/11/23.
//

#ifndef LIB_H
#define LIB_H

#ifdef __cplusplus
extern "C" {
#endif

int process(const char* input,
            const unsigned int input_size, const char* output, const unsigned int output_size,
            const char* value, const unsigned int value_size,
            const char* start, const unsigned int start_size, const char* end, const unsigned int end_size);

#ifdef __cplusplus
}
#endif

#endif //LIB_H
