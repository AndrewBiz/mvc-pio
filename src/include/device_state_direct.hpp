/*
*/
#ifndef DEVICE_STATE_DIRECT_HPP
#define DEVICE_STATE_DIRECT_HPP
#include "device_state.hpp"
#include "device_view_screen_direct.hpp"

class DeviceStateDirect : public DeviceState {
public:
    DeviceStateDirect(DeviceModel *);
    virtual ~DeviceStateDirect();
    virtual void save_to_memory(int memory_slot);
    virtual void load_from_memory(int memory_slot);
    virtual void change_value(int8_t steps);
    virtual void next_step_level();
    virtual void prev_step_level();
    virtual State click_change_state();
    virtual State long_click_change_state();
private:
    DeviceViewScreenDirect _screen;
};
#endif
