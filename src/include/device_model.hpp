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
    void save_to_memory(int memory_slot);
    void load_from_memory(int memory_slot);

    void change_value(int8_t steps);
    uint32_t get_value();
    uint32_t get_step_level_n();
    void next_step_level_n();
    void prev_step_level_n();

    void change_dvalue(int8_t steps);
    uint32_t get_dvalue();
    uint32_t get_step_level_d();
    void next_step_level_d();
    void prev_step_level_d();

    void change_cvalue(int8_t steps);
    uint32_t get_cvalue();
    uint32_t get_step_level_c();
    void next_step_level_c();
    void prev_step_level_c();

protected:
    static const uint32_t DefValue = 1000;
    static const uint32_t MaxValue = 20000000;
    static const uint32_t MinValue = 0;
    static const uint8_t MaxStepLevelsN = 7;
    static const uint8_t DefStepLevelIndexN = 3;
    static constexpr uint32_t StepLevelN[MaxStepLevelsN] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };

    static const uint32_t DefDValue = 1000;
    static const uint32_t MaxDValue = 690000000;
    static const uint32_t MinDValue = 0;
    static const uint8_t MaxStepLevelsD = 9;
    static const uint8_t DefStepLevelIndexD = 4;
    static constexpr uint32_t StepLevelD[MaxStepLevelsD] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

    static const uint32_t DefCValue = 125000000;
    static const uint32_t ThresholdCValue = 20000000;
    static const uint8_t MaxStepLevelsC = 5;
    static const uint8_t DefStepLevelIndexC = 0;
    static constexpr uint32_t StepLevelC[MaxStepLevelsC] = { 1, 10, 100, 1000, 10000 };
private:
    uint32_t _value;    // master value in Normal mode
    uint8_t _step_level_index_n;

    uint32_t _dvalue;   // master value in Direct mode
    uint8_t _step_level_index_d;

    uint32_t _cvalue;   // master value in Calibrate mode
    uint8_t _step_level_index_c;

    void _calculate_value();
    void _calculate_dvalue();
};
#endif
