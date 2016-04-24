/*
*/
#ifndef DEVICE_STATE_HPP
#define DEVICE_STATE_HPP
#include <stdint.h>
#include "device_model.hpp"

class DeviceState {
public:
    DeviceState(DeviceModel *);
    virtual ~DeviceState() = default;
    virtual void save_to_memory(int memory_slot) = 0; //pure virtual function
    virtual void load_from_memory(int memory_slot) = 0; //pure virtual function
    virtual void change_value(int8_t steps) = 0; //pure virtual function
    virtual void next_step_level() = 0; //pure virtual function
    virtual void prev_step_level() = 0; //pure virtual function

protected:
    // DeviceController * _controller;  //Context who uses the State
    DeviceModel * _model;
};
#endif
