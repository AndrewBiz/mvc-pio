/*
*/
#include "include/device_state_direct.hpp"
#include <iostream>

using namespace std;

DeviceStateDirect::DeviceStateDirect(DeviceModel * dm) :
    DeviceState(dm)
{
    cout << "DeviceStateDirect constructor triggered" << endl;
}

DeviceStateDirect::~DeviceStateDirect() {
    cout << "DeviceStateDirect ~destructor triggered" << endl;
    cout << "  ... here save state to be implemented (in needed)" << endl;
}

void DeviceStateDirect::save_to_memory(int memory_slot) {
    cout << "DeviceStateDirect::save_to_memory " << memory_slot << endl;
    _model->save_to_memory(memory_slot);
};

void DeviceStateDirect::load_from_memory(int memory_slot) {
    cout << "DeviceStateDirect::load_from_memory " << memory_slot << endl;
    _model->load_from_memory(memory_slot);
};

void DeviceStateDirect::change_value(int8_t steps) {
    cout << "DeviceStateDirect::change_value" << endl;
    _model->change_dvalue(steps);
};

void DeviceStateDirect::next_step_level() {
    cout << "DeviceStateDirect::next_step_level" << endl;
    _model->next_step_level_d();
};

void DeviceStateDirect::prev_step_level() {
    cout << "DeviceStateDirect::prev_step_level" << endl;
    _model->prev_step_level_d();
};

State DeviceStateDirect::click_change_state() {
    cout << "DeviceStateDirect::click_change_state" << endl;
    return State::Normal;
};

State DeviceStateDirect::long_click_change_state() {
    cout << "DeviceStateDirect::long_click_change_state" << endl;
    return State::Calibration;
};
