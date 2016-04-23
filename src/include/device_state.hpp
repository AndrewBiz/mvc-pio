/*
*/
#ifndef DEVICE_STATE_HPP
#define DEVICE_STATE_HPP
#include <stdint.h>

class DeviceController; // forward declaration

class DeviceState {
public:
    DeviceState(DeviceController *);
    virtual ~DeviceState() = default;
    virtual void save_to_memory(int memory_slot) = 0; //pure virtual function
    virtual void load_from_memory(int memory_slot) = 0; //pure virtual function
    virtual void change_value(int8_t steps) = 0; //pure virtual function
    virtual void next_step_level() = 0; //pure virtual function
    virtual void prev_step_level() = 0; //pure virtual function

private:
    DeviceController * _controller;  //Context who uses the State
};
#endif
