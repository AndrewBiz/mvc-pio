/*
*/
#ifndef DEVICE_STATE_NORMAL_HPP
#define DEVICE_STATE_NORMAL_HPP
#include "device_state.hpp"

class DeviceStateNormal : public DeviceState {
public:
    DeviceStateNormal(DeviceModel *);
    virtual ~DeviceStateNormal();
    virtual void save_to_memory(int memory_slot);
    virtual void load_from_memory(int memory_slot);
    virtual void change_value(int8_t steps);
    virtual void next_step_level();
    virtual void prev_step_level();
    virtual State click_change_state();
    virtual State long_click_change_state();
};
#endif
