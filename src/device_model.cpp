/*
    device implementation
*/
#include "include/device_model.hpp"
#include <iostream>

using namespace std;

constexpr uint32_t DeviceModel::StepLevel[MaxStepLevels];

DeviceModel::DeviceModel() :
    _value(0),
    _step_level_index(DefStepLevelIndex)
{
    cout << "DeviceModel constructor triggered" << endl;
}

void DeviceModel::initialize() {
    cout << "DeviceModel::initialize triggered" << endl;
    srand(123);
    _value = rand() % 10000;
    cout << "... reading default value from Memory M0: " << _value << endl;
    _step_level_index = rand() % MaxStepLevels;
    cout << "... reading default step_level from Memory M0: " << StepLevel[_step_level_index]\
         << " (" << int(_step_level_index) << ") " << endl;
    notify_observers();
}

void DeviceModel::save_to_memory(int memory_slot) {
    cout << "DeviceModel::save_to_memory - saving to slot " << memory_slot << endl;
};

void DeviceModel::load_from_memory(int memory_slot) {
    cout << "DeviceModel::load_from_memory - loading from slot " << memory_slot << endl;
};

void DeviceModel::set_value(uint32_t v) {
    _value = v;
    cout << "DeviceModel::set_value " << _value << " triggered" << endl;
    notify_observers();
}

void DeviceModel::change_value(int8_t steps) {
    int32_t delta = get_step_level() * steps;
    cout << "DeviceModel::change_value triggered, delta=steps*level= " << delta << endl;
    if (delta < 0) {
        _value = (_value >= uint32_t(-delta)) ? _value + delta : _value;
    } else {
        _value = (_value + delta <= MaxValue) ? _value + delta : _value;
    }
    notify_observers();
}

void DeviceModel::next_step_level() {
    cout << "DeviceModel::next_step_level triggered" << endl;
    _step_level_index = (_step_level_index + 1 >= MaxStepLevels) ? MaxStepLevels - 1 : _step_level_index + 1;
    notify_observers();
}

void DeviceModel::prev_step_level() {
    cout << "DeviceModel::prev_step_level triggered" << endl;
    _step_level_index = (_step_level_index - 1 < 0) ? 0 : _step_level_index - 1;
    notify_observers();
}

uint32_t DeviceModel::get_value() {
    cout << "DeviceModel::get_value triggered" << endl;
    return _value;
}

uint32_t DeviceModel::get_step_level() {
    cout << "DeviceModel::get_step_level triggered" << endl;
    return StepLevel[_step_level_index];
}
