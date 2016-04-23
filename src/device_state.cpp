/*
*/
#include "include/device_state.hpp"
#include <iostream>

using namespace std;

DeviceState::DeviceState(DeviceController * dc) :
    _controller(dc)
{
    cout << "DeviceState constructor triggered" << endl;
}
