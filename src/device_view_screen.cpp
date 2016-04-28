/*
*/
#include "include/device_view_screen.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

DeviceViewScreen::DeviceViewScreen(DeviceModel * m) :
    _model(m),
    _state(State::Null)
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
    switch (_state) {
    case State::Normal:
        snprintf(_scr_buf1, ScrBufSize, "%uHz(%s)                  ",\
            _model->get_value(), _to_kilo(buf, 5, _model->get_step_level_n()));
        snprintf(_scr_buf2, ScrBufSize, "%u                        ",\
            _model->get_dvalue());
        break;
    case State::Direct:
        snprintf(_scr_buf1, ScrBufSize, "%uHz                      ",\
            _model->get_value());
        snprintf(_scr_buf2, ScrBufSize, "%u (%s)                   ",\
            _model->get_dvalue(), _to_kilo(buf, 5, _model->get_step_level_d()));
        break;
    case State::Calibration:
//TODO
        strncpy(_scr_buf1, "UNDER           ", ScrBufSize-1);
        strncpy(_scr_buf2, "CONSTRUCTION !!!", ScrBufSize-1);
        break;
    default:
        strncpy(_scr_buf1, "ERROR!ERROR!XXXXYYY", ScrBufSize-1);
        strncpy(_scr_buf2, "ERROR!ERROR!ERROYYY", ScrBufSize-1);
        break;
    }
    draw_screen();
}

void DeviceViewScreen::draw_screen() {
    cout << "\n        ------------------" << endl;
    cout <<   "SCREEN: |" << _scr_buf1 << "|" << endl;
    cout <<   "        |" << _scr_buf2 << "|" << endl;
    cout <<   "        ------------------" << "\n" << endl;
}

void DeviceViewScreen::change_state_to(State s) {
    cout << "DeviceViewScreen:change_state_to " << int(s) << " triggered" << endl;
    _state = s;
    // Saving current screen in buffer
    // char tmp_buf1[ScrBufSize];
    // char tmp_buf2[ScrBufSize];
    // strncpy(tmp_buf1, _scr_buf1, ScrBufSize);
    // strncpy(tmp_buf2, _scr_buf2, ScrBufSize);
    snprintf(_scr_buf1, ScrBufSize, " Changed State    ");
    snprintf(_scr_buf2, ScrBufSize, " to : %i          ", int(_state));
    draw_screen();
    // here Delay goes
    // restoring previous screen
    // strncpy(_scr_buf1, tmp_buf1, ScrBufSize);
    // strncpy(_scr_buf2, tmp_buf2, ScrBufSize);
    // draw_screen();
    update();
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
