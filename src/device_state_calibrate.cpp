/*
*/
#include "include/device_state_calibrate.hpp"
#include <iostream>

using namespace std;

DeviceStateCalibrate::DeviceStateCalibrate(DeviceModel * dm) :
    DeviceState(dm),
    _screen(DeviceViewScreenCalibrate(dm))
{
    cout << "DeviceStateCalibrate constructor triggered" << endl;
}

DeviceStateCalibrate::~DeviceStateCalibrate() {
    cout << "DeviceStateCalibrate ~destructor triggered" << endl;
    cout << "  ... here save state to be implemented (in needed)" << endl;
}

void DeviceStateCalibrate::save_to_memory(int memory_slot) {
    cout << "DeviceStateCalibrate::save_to_memory " << memory_slot << endl;
};

void DeviceStateCalibrate::load_from_memory(int memory_slot) {
    cout << "DeviceStateCalibrate::load_from_memory " << memory_slot << endl;
};

void DeviceStateCalibrate::change_value(int8_t steps) {
    cout << "DeviceStateCalibrate::change_value" << endl;
    _model->change_cvalue(steps);
};

void DeviceStateCalibrate::next_step_level() {
    cout << "DeviceStateCalibrate::next_step_level" << endl;
    _model->next_step_level_c();
};

void DeviceStateCalibrate::prev_step_level() {
    cout << "DeviceStateCalibrate::prev_step_level" << endl;
    _model->prev_step_level_c();
};

State DeviceStateCalibrate::click_change_state() {
    cout << "DeviceStateCalibrate::click_change_state" << endl;
    cout << "... here to save calibrated value to EEPROM" << endl;
    return State::Normal;
};

State DeviceStateCalibrate::long_click_change_state() {
    cout << "DeviceStateCalibrate::long_click_change_state" << endl;
    return State::Null;
};
