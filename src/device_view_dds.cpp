/*
*/
#include "include/device_view_dds.hpp"
#include <iostream>

using namespace std;

DeviceViewDDS::DeviceViewDDS(DeviceModel* m) {
    cout << "DeviceViewDDS constructor triggered" << endl;
    _model = m;
    _model->attach_observer(this);
}

DeviceViewDDS::~DeviceViewDDS() {
    cout << "DeviceViewDDS ~destructor triggered" << endl;
    _model->detach_observer(this);
}

void DeviceViewDDS::update() {
    cout << "DeviceViewDDS::update triggered" << endl;
    set_dds();
}

void DeviceViewDDS::set_dds() {
    cout << "\nDDS: " << _model->get_value() << "\n" << endl;
}
