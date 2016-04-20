/*
*/
#include "include/device_view_screen.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

DeviceViewScreen::DeviceViewScreen(DeviceModel * m) :
    _model(m)
{
    snprintf(_scr_buf, ScrBufSize, "                    ");
    cout << "DeviceViewScreen constructor triggered" << endl;
    _model->attach_observer(this);
}

DeviceViewScreen::~DeviceViewScreen() {
    cout << "DeviceViewScreen ~destructor triggered" << endl;
    _model->detach_observer(this);
}

void DeviceViewScreen::update() {
    cout << "DeviceViewScreen::update triggered" << endl;
    snprintf(_scr_buf, ScrBufSize, "%d Hz", _model->get_value());
    draw_screen();
}

void DeviceViewScreen::draw_screen() {
    cout << "\n        ----------------------" << endl;
    cout <<   "SCREEN: |" << _scr_buf <<   "|" << endl;
    cout <<   "        ----------------------" << "\n" << endl;
}
