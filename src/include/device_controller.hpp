/*
*/
#ifndef DEVICE_CONTROLLER_HPP
#define DEVICE_CONTROLLER_HPP

#include "controller.hpp"
#include "device_model.hpp"
#include "device_view_screen.hpp"

class DeviceController : public Controller {
public:
    DeviceController(DeviceModel *);
    virtual ~DeviceController();
    virtual void handle_event(char);
    virtual void change_value(int steps);
    virtual void next_step_level();
    virtual void prev_step_level();
private:
    DeviceModel * _model;
    DeviceViewScreen * _screen;
    virtual void save_to_memory(int memory_slot);
    virtual void load_from_memory(int memory_slot);
};

#endif
