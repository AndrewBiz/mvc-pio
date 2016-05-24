/*
*/
#ifndef DEVICE_STATE_CALIBRATE_HPP
#define DEVICE_STATE_CALIBRATE_HPP
#include "device_state.hpp"
#include "device_view_screen_calibrate.hpp"

class DeviceStateCalibrate : public DeviceState {
public:
    DeviceStateCalibrate(DeviceModel *);
    virtual ~DeviceStateCalibrate();
    virtual void save_to_memory(int memory_slot);
    virtual void load_from_memory(int memory_slot);
    virtual void change_value(int8_t steps);
    virtual void next_step_level();
    virtual void prev_step_level();
    virtual State click_change_state();
    virtual State long_click_change_state();
private:
    DeviceViewScreenCalibrate _screen;
};
#endif
