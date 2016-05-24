/*
*/
#ifndef DEVICE_VIEW_SCREEN_CALIBRATE_HPP
#define DEVICE_VIEW_SCREEN_CALIBRATE_HPP

#include "device_view_screen.hpp"

class DeviceViewScreenCalibrate : public DeviceViewScreen {
public:
    DeviceViewScreenCalibrate(DeviceModel *);
    virtual ~DeviceViewScreenCalibrate();
    virtual void update();
};

#endif
