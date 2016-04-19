/*
    device implementation
*/
#include "include/device_model.hpp"
#include <iostream>

using namespace std;

DeviceModel::DeviceModel() {
    cout << "DeviceModel constructor triggered" << endl;
    _value = 0;
}

void DeviceModel::set_value(int v) {
    _value = v;
    cout << "DeviceModel::set_value " << _value << " triggered" << endl;
    notify_observers();
}

int DeviceModel::get_value() {
    cout << "DeviceModel::get_value triggered" << endl;
    return _value;
}
