/*
*/
#ifndef DEVICE_CONTROLLER_HPP
#define DEVICE_CONTROLLER_HPP

#include "device_model.hpp"
#include "device_view_screen.hpp"
#include "device_state.hpp"

class DeviceController {
public:
    DeviceController(DeviceModel *);
    ~DeviceController();
    void handle_event(char);
private:
    DeviceModel * _model;
    DeviceState * _state;
    void change_state_to(State new_state);
};
#endif
