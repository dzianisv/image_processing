#ifndef LABEL_H
#define LABEL_H
#include <stdint.h>

struct label_t {
    uint16_t label;

    bool operator==(label_t& operand) {
        return this->label == operand.label;
    }

    bool operator!=(label_t& operand) {
        return this->label != operand.label;
    }
};


typedef uint32_t ClassID;

#endif // LABEL_H
