/*
*/
#include "include/device_view_screen.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

DeviceViewScreen::DeviceViewScreen(DeviceModel * m) :
    _model(m)
{
    memset(_scr_buf1, '\0', ScrBufSize);
    memset(_scr_buf2, '\0', ScrBufSize);
    cout << "DeviceViewScreen constructor triggered" << endl;
    _model->attach_observer(this);
}

DeviceViewScreen::~DeviceViewScreen() {
    cout << "DeviceViewScreen ~destructor triggered" << endl;
    _model->detach_observer(this);
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
