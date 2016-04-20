/*
    device implementation
*/
#include "include/device_model.hpp"
#include <iostream>

using namespace std;

constexpr uint32_t DeviceModel::StepLevel[MaxStepLevelIndex];

DeviceModel::DeviceModel() :
    _value(0),
    _step_level_index(DefStepLevelIndex)
{
    cout << "DeviceModel constructor triggered" << endl;
}

void DeviceModel::initialize() {
    cout << "DeviceModel::initialize triggered" << endl;
    srand(232323);
    _value = rand() % 10000;
    cout << "... reading default value from Memory: " << _value << endl;
    _step_level_index = rand() % MaxStepLevelIndex;
    cout << "... reading default step_level from Memory: " << StepLevel[_step_level_index]\
         << " (" << int(_step_level_index) << ") " << endl;
    notify_observers();
}

void DeviceModel::set_value(int v) {
    _value = v;
    cout << "DeviceModel::set_value " << _value << " triggered" << endl;
    notify_observers();
}

int DeviceModel::get_value() {
    cout << "DeviceModel::get_value triggered" << endl;
    return _value;
}
