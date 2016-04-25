/*
*/
#ifndef ENUM_STATE_HPP
#define ENUM_STATE_HPP
#include <stdint.h>

enum class State : uint8_t {
    Null,
    Normal,
    Direct,
    Calibration
};
#endif
