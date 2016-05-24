/*
*/
#include "include/device_view_screen_calibrate.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

DeviceViewScreenCalibrate::DeviceViewScreenCalibrate(DeviceModel * m) :
    DeviceViewScreen(m)
{
    cout << "DeviceViewScreenCalibrate constructor triggered" << endl;
    update();
}

DeviceViewScreenCalibrate::~DeviceViewScreenCalibrate() {
    cout << "DeviceViewScreenCalibrate ~destructor triggered" << endl;
}

void DeviceViewScreenCalibrate::update() {
    cout << "DeviceViewScreenCalibrate::update triggered" << endl;
    char buf[5];
    snprintf(_scr_buf1, ScrBufSize, "%uHz                      ",\
        _model->get_value());
    snprintf(_scr_buf2, ScrBufSize, "%u(%s)                    ",\
        _model->get_cvalue(), _to_kilo(buf, 5, _model->get_step_level_c()));
    draw_screen();
}
