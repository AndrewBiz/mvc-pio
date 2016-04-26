/*
*/
#include "include/device_view_screen.hpp"
#include <iostream>
#include <cstdio>

using namespace std;

DeviceViewScreen::DeviceViewScreen(DeviceModel * m) :
    _model(m)
{
    snprintf(_scr_buf1, ScrBufSize, "1234567890123456");
    snprintf(_scr_buf2, ScrBufSize, "1234567890123456");
    cout << "DeviceViewScreen constructor triggered" << endl;
    _model->attach_observer(this);
}

DeviceViewScreen::~DeviceViewScreen() {
    cout << "DeviceViewScreen ~destructor triggered" << endl;
    _model->detach_observer(this);
}

void DeviceViewScreen::update() {
    cout << "DeviceViewScreen::update triggered" << endl;
    snprintf(_scr_buf1, ScrBufSize, "%uHz(%u)                  ", _model->get_value(), _model->get_step_level_n());
    snprintf(_scr_buf2, ScrBufSize, "%u (%u)                   ", _model->get_dvalue(), _model->get_step_level_d());
    draw_screen();
}

void DeviceViewScreen::draw_screen() {
    cout << "\n        ------------------" << endl;
    cout <<   "SCREEN: |" << _scr_buf1 << "|" << endl;
    cout <<   "        |" << _scr_buf2 << "|" << endl;
    cout <<   "        ------------------" << "\n" << endl;
}
