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
    virtual ~DeviceController();
    virtual void handle_event(char);
private:
    DeviceModel * _model;
    DeviceViewScreen * _screen;
    DeviceState * _state;
};
#endif
