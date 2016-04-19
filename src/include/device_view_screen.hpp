/*
*/
#ifndef DEVICE_VIEW_SCREEN_HPP
#define DEVICE_VIEW_SCREEN_HPP

#include "view.hpp"
#include "device_model.hpp"

class DeviceViewScreen : public View {
public:
    DeviceViewScreen(DeviceModel*);
    virtual ~DeviceViewScreen();
    virtual void update();
    void draw_screen();
private:
    DeviceModel* _model;
};

#endif
