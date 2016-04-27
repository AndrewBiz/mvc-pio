/*
*/
#include "include/device_state_calibrate.hpp"
#include <iostream>

using namespace std;

DeviceStateCalibrate::DeviceStateCalibrate(DeviceModel * dm) :
    DeviceState(dm)
{
    cout << "DeviceStateCalibrate constructor triggered" << endl;
}

DeviceStateCalibrate::~DeviceStateCalibrate() {
    cout << "DeviceStateCalibrate ~destructor triggered" << endl;
    cout << "  ... here save state to be implemented (in needed)" << endl;
}

void DeviceStateCalibrate::save_to_memory(int memory_slot) {
    // cout << "DeviceStateCalibrate::save_to_memory " << memory_slot << endl;
    // _model->save_to_memory(memory_slot);
};

void DeviceStateCalibrate::load_from_memory(int memory_slot) {
    // cout << "DeviceStateCalibrate::load_from_memory " << memory_slot << endl;
    // _model->load_from_memory(memory_slot);
};

void DeviceStateCalibrate::change_value(int8_t steps) {
    cout << "FAKE! DeviceStateCalibrate::change_value" << endl;
//TODO
    _model->change_value(steps);
};

void DeviceStateCalibrate::next_step_level() {
    cout << "FAKE! DeviceStateCalibrate::next_step_level" << endl;
//TODO
    _model->next_step_level_n();
};

void DeviceStateCalibrate::prev_step_level() {
    cout << "FAKE! DeviceStateCalibrate::prev_step_level" << endl;
//TODO
    _model->prev_step_level_n();
};

State DeviceStateCalibrate::click_change_state() {
    cout << "DeviceStateCalibrate::click_change_state" << endl;
    cout << "... here to save calibrated value to EEPROM" << endl;
    return State::Normal;
};

State DeviceStateCalibrate::long_click_change_state() {
    // cout << "DeviceStateCalibrate::long_click_change_state" << endl;
    return State::Null;
};
