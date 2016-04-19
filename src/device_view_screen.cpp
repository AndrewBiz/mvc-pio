/*
*/
#include "include/device_view_screen.hpp"
#include <iostream>

using namespace std;

DeviceViewScreen::DeviceViewScreen(DeviceModel* m) {
    cout << "DeviceViewScreen constructor triggered" << endl;
    _model = m;
    _model->attach_observer(this);
}

DeviceViewScreen::~DeviceViewScreen() {
    cout << "DeviceViewScreen ~destructor triggered" << endl;
    _model->detach_observer(this);
}

void DeviceViewScreen::update() {
    cout << "DeviceViewScreen::update triggered" << endl;
    draw_screen();
}

void DeviceViewScreen::draw_screen() {
    cout << "\nSCREEN: " << _model->get_value() << "\n" << endl;
}
