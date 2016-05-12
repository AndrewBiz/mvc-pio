/*
*/
#ifndef DEVICE_VIEW_SCREEN_NORMAL_HPP
#define DEVICE_VIEW_SCREEN_NORMAL_HPP

#include "device_view_screen.hpp"

class DeviceViewScreenNormal : public DeviceViewScreen {
public:
    DeviceViewScreenNormal(DeviceModel *);
    virtual ~DeviceViewScreenNormal();
    virtual void update();
};

#endif
