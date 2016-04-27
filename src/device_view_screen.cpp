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
    char buf[5];
    snprintf(_scr_buf1, ScrBufSize, "%uHz(%s)                  ", _model->get_value(), _to_kilo(buf, 5, _model->get_step_level_n()));
    snprintf(_scr_buf2, ScrBufSize, "%u (%s)                   ", _model->get_dvalue(), _to_kilo(buf, 5, _model->get_step_level_d()));
    draw_screen();
}

void DeviceViewScreen::draw_screen() {
    cout << "\n        ------------------" << endl;
    cout <<   "SCREEN: |" << _scr_buf1 << "|" << endl;
    cout <<   "        |" << _scr_buf2 << "|" << endl;
    cout <<   "        ------------------" << "\n" << endl;
}

char * DeviceViewScreen::_to_kilo(char * buf, int buf_len, uint32_t v) {
    if (v >= 1000000) {
        snprintf(buf, buf_len, "%uM", uint16_t(v / 1000000));
    } else if (v >= 1000) {
        snprintf(buf, buf_len, "%uK", uint16_t(v / 1000));
    } else {
        snprintf(buf, buf_len, "%u", v);
    }
    return buf;
}
