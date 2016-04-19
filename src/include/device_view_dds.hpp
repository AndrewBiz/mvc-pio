/*
*/
#ifndef DEVICE_VIEW_DDS_HPP
#define DEVICE_VIEW_DDS_HPP

#include "view.hpp"
#include "device_model.hpp"

class DeviceViewDDS : public View {
public:
    DeviceViewDDS(DeviceModel *);
    virtual ~DeviceViewDDS();
    virtual void update();
    void set_dds();
private:
    DeviceModel *_model;
};

#endif
