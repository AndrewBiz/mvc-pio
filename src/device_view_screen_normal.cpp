/*
*/
#include "include/device_view_screen_normal.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

DeviceViewScreenNormal::DeviceViewScreenNormal(DeviceModel * m) :
    DeviceViewScreen(m)
{
    cout << "DeviceViewScreenNormal constructor triggered" << endl;
    update();
}

DeviceViewScreenNormal::~DeviceViewScreenNormal() {
    cout << "DeviceViewScreenNormal ~destructor triggered" << endl;
}

void DeviceViewScreenNormal::update() {
    cout << "DeviceViewScreenNormal::update triggered" << endl;
    char buf[5];
    snprintf(_scr_buf1, ScrBufSize, "%uHz(%s)                  ",\
        _model->get_value(), _to_kilo(buf, 5, _model->get_step_level_n()));
    snprintf(_scr_buf2, ScrBufSize, "%u                        ",\
        _model->get_dvalue());
    draw_screen();
}
