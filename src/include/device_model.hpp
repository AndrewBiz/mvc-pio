/*
*/
#ifndef DEVICE_MODEL_HPP
#define DEVICE_MODEL_HPP

#include "model.hpp"
#include <stdint.h>

class DeviceModel : public Model {
public:
    DeviceModel();
    void initialize();
    void set_value(int v);
    int get_value();

protected:
    static const uint8_t MaxStepLevelIndex = 7;
    static const uint8_t DefStepLevelIndex = 3;
    static constexpr uint32_t StepLevel[MaxStepLevelIndex] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

private:
    int _value;
    uint8_t _step_level_index;
};

#endif
