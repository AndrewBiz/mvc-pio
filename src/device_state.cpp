/*
*/
#include "include/device_state.hpp"
#include <iostream>

using namespace std;

DeviceState::DeviceState(DeviceModel * dm) :
    _model(dm)
{
    cout << "DeviceState constructor triggered" << endl;
}
