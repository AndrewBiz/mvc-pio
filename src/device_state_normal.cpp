/*
*/
#include "include/device_state_normal.hpp"
#include <iostream>

using namespace std;

DeviceStateNormal::DeviceStateNormal(DeviceModel * dm) :
    DeviceState(dm),
    _screen(DeviceViewScreenNormal(dm))
{
    cout << "DeviceStateNormal constructor triggered" << endl;
}

DeviceStateNormal::~DeviceStateNormal() {
    cout << "DeviceStateNormal ~destructor triggered" << endl;
    cout << "  ... here save state to be implemented (in needed)" << endl;
}

void DeviceStateNormal::save_to_memory(int memory_slot) {
    cout << "DeviceStateNormal::save_to_memory " << memory_slot << endl;
    _model->save_to_memory(memory_slot);
};

void DeviceStateNormal::load_from_memory(int memory_slot) {
    cout << "DeviceStateNormal::load_from_memory " << memory_slot << endl;
    _model->load_from_memory(memory_slot);
};

void DeviceStateNormal::change_value(int8_t steps) {
    cout << "DeviceStateNormal::change_value" << endl;
    _model->change_value(steps);
};

void DeviceStateNormal::next_step_level() {
    cout << "DeviceStateNormal::next_step_level" << endl;
    _model->next_step_level_n();
};

void DeviceStateNormal::prev_step_level() {
    cout << "DeviceStateNormal::prev_step_level" << endl;
    _model->prev_step_level_n();
};

State DeviceStateNormal::click_change_state() {
    cout << "DeviceStateNormal::click_change_state" << endl;
    return State::Direct;
};

State DeviceStateNormal::long_click_change_state() {
    cout << "DeviceStateNormal::long_click_change_state" << endl;
    return State::Calibration;
};
