/*
    device implementation
*/
#include "include/device_model.hpp"
#include <iostream>

using namespace std;

DeviceModel::DeviceModel() :
    _value(DefValue),
    _step_level_index_n(DefStepLevelIndexN),
    _dvalue(DefDValue),
    _step_level_index_d(DefStepLevelIndexD),
    _cvalue(DefCValue),
    _step_level_index_c(DefStepLevelIndexC)
{
    cout << "DeviceModel constructor triggered" << endl;
    initialize();
}

void DeviceModel::initialize() {
    cout << "DeviceModel::initialize triggered" << endl;
    cout << "... reading default value from Memory M0: " << endl;
    cout << "...... value = " << _value << endl;
    cout << "...... cvalue = " << _cvalue << endl;
    _calculate_dvalue();
    cout << "... reading default step_level from Memory M0: " << StepLevelN[_step_level_index_n]\
         << " (" << int(_step_level_index_n) << ") " << endl;
}

void DeviceModel::save_to_memory(int memory_slot) {
    cout << "DeviceModel::save_to_memory - saving to slot " << memory_slot << endl;
};

void DeviceModel::load_from_memory(int memory_slot) {
    cout << "DeviceModel::load_from_memory - loading from slot " << memory_slot << endl;
};

void DeviceModel::_calculate_value() {
    cout << "DeviceModel::_calculate_value triggered " << endl;
    _value = ((uint64_t)_dvalue * (uint64_t)_cvalue) >> 32;
    cout << "... dvalue = " << _dvalue << endl;
    cout << "...... calculated value = " << _value << endl;
};

void DeviceModel::_calculate_dvalue() {
    cout << "DeviceModel::_calculate_dvalue triggered " << endl;
    _dvalue = ((uint64_t)_value << 32) / _cvalue;
    cout << "... value = " << _value << endl;
    cout << "...... calculated dvalue = " << _dvalue << endl;
};

// functions for Normal mode
constexpr uint32_t DeviceModel::StepLevelN[MaxStepLevelsN];

void DeviceModel::change_value(int8_t steps) {
    int32_t delta = get_step_level_n() * steps;
    cout << "DeviceModel::change_value triggered, delta=steps*level= " << delta << endl;
    if (delta < 0) {
        _value = (_value >= uint32_t(-delta)) ? _value + delta : _value;
    } else {
        _value = (_value + delta <= MaxValue) ? _value + delta : _value;
    }
    _calculate_dvalue();
    notify_observers();
}

void DeviceModel::next_step_level_n() {
    cout << "DeviceModel::next_step_level_n triggered" << endl;
    _step_level_index_n = (_step_level_index_n + 1 >= MaxStepLevelsN) ? MaxStepLevelsN - 1 : _step_level_index_n + 1;
    notify_observers();
}

void DeviceModel::prev_step_level_n() {
    cout << "DeviceModel::prev_step_level_n triggered" << endl;
    _step_level_index_n = (_step_level_index_n - 1 < 0) ? 0 : _step_level_index_n - 1;
    notify_observers();
}

uint32_t DeviceModel::get_value() {
    cout << "DeviceModel::get_value triggered" << endl;
    return _value;
}

uint32_t DeviceModel::get_step_level_n() {
    cout << "DeviceModel::get_step_level_n triggered" << endl;
    return StepLevelN[_step_level_index_n];
}

// functions for Direct mode
constexpr uint32_t DeviceModel::StepLevelD[MaxStepLevelsD];

void DeviceModel::change_dvalue(int8_t steps) {
    int32_t delta = get_step_level_d() * steps;
    cout << "DeviceModel::change_dvalue triggered, delta=steps*level= " << delta << endl;
    if (delta < 0) {
        _dvalue = (_dvalue >= uint32_t(-delta)) ? _dvalue + delta : _dvalue;
    } else {
        _dvalue = (_dvalue + delta <= MaxDValue) ? _dvalue + delta : _dvalue;
    }
    _calculate_value();
    notify_observers();
}

void DeviceModel::next_step_level_d() {
    cout << "DeviceModel::next_step_level_d triggered" << endl;
    _step_level_index_d = (_step_level_index_d + 1 >= MaxStepLevelsD) ? MaxStepLevelsD - 1 : _step_level_index_d + 1;
    notify_observers();
}

void DeviceModel::prev_step_level_d() {
    cout << "DeviceModel::prev_step_level_d triggered" << endl;
    _step_level_index_d = (_step_level_index_d - 1 < 0) ? 0 : _step_level_index_d - 1;
    notify_observers();
}

uint32_t DeviceModel::get_dvalue() {
    cout << "DeviceModel::get_dvalue triggered" << endl;
    return _dvalue;
}

uint32_t DeviceModel::get_step_level_d() {
    cout << "DeviceModel::get_step_level_d triggered" << endl;
    return StepLevelD[_step_level_index_d];
}
