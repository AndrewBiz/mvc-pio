/*
*/
#include "include/device_state_normal.hpp"
#include <iostream>

using namespace std;

DeviceStateNormal::DeviceStateNormal(DeviceController * dc) :
    DeviceState(dc)
{
    cout << "DeviceStateNormal constructor triggered" << endl;
}

void DeviceStateNormal::save_to_memory(int memory_slot) {
    cout << "DeviceStateNormal::save_to_memory - saving to slot " << memory_slot << endl;
};

void DeviceStateNormal::load_from_memory(int memory_slot) {
    cout << "DeviceStateNormal::load_from_memory - loading from slot " << memory_slot << endl;
};

void DeviceStateNormal::change_value(int8_t steps) {
    cout << "FAKE!! DeviceStateNormal::change_value" << endl;
};

void DeviceStateNormal::next_step_level() {
    cout << "FAKE!! DeviceStateNormal::next_step_level" << endl;
};

void DeviceStateNormal::prev_step_level() {
    cout << "FAKE!! DeviceStateNormal::prev_step_level" << endl;
};
