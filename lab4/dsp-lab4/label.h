#ifndef LABEL_H
#define LABEL_H
#include <stdint.h>

struct label_t {
    uint16_t label;

    bool operator==(label_t& operand) {
        return this->label == operand.label;
    }
};

#endif // LABEL_H
