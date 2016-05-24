/*
*/
#ifndef DEVICE_VIEW_SCREEN_DIRECT_HPP
#define DEVICE_VIEW_SCREEN_DIRECT_HPP

#include "device_view_screen.hpp"

class DeviceViewScreenDirect : public DeviceViewScreen {
public:
    DeviceViewScreenDirect(DeviceModel *);
    virtual ~DeviceViewScreenDirect();
    virtual void update();
};

#endif
