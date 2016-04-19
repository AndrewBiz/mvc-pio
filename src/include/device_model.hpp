/*
*/
#ifndef DEVICE_MODEL_HPP
#define DEVICE_MODEL_HPP

#include "model.hpp"

class DeviceModel : public Model {
public:
    DeviceModel();
    void set_value(int v);
    int get_value();

private:
    int _value;
};

#endif
