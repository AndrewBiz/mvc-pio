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
    void set_value(uint32_t v);
    void change_value(int8_t steps);
    uint32_t get_value();
    uint32_t get_step_level();
    void next_step_level();
    void prev_step_level();

protected:
    static const uint32_t MaxValue = 20000000;
    static const uint32_t MinValue = 0;
    static const uint8_t MaxStepLevels = 7;
    static const uint8_t DefStepLevelIndex = 3;
    static constexpr uint32_t StepLevel[MaxStepLevels] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

private:
    uint32_t _value;
    uint8_t _step_level_index;
};

#endif
