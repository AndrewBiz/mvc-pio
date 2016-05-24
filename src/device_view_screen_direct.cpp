/*
*/
#include "include/device_view_screen_direct.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

DeviceViewScreenDirect::DeviceViewScreenDirect(DeviceModel * m) :
    DeviceViewScreen(m)
{
    cout << "DeviceViewScreenDirect constructor triggered" << endl;
    update();
}

DeviceViewScreenDirect::~DeviceViewScreenDirect() {
    cout << "DeviceViewScreenDirect ~destructor triggered" << endl;
}

void DeviceViewScreenDirect::update() {
    cout << "DeviceViewScreenDirect::update triggered" << endl;
    char buf[5];
    snprintf(_scr_buf1, ScrBufSize, "%uHz                      ",\
        _model->get_value());
    snprintf(_scr_buf2, ScrBufSize, "%u(%s)                    ",\
        _model->get_dvalue(), _to_kilo(buf, 5, _model->get_step_level_d()));
    draw_screen();
}
