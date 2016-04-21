/*
    MVC patter prototyping
    Andrew Bizyaev (ANB) github.com/andrewbiz
*/
#include <iostream>
#include "include/device_model.hpp"
#include "include/device_controller.hpp"

using namespace std;

int main() {
    cout << "Hello, Andrew, learning MVC with platformio, eh?" << endl;

    DeviceModel * device_model = new DeviceModel;
    DeviceController * device_controller = new DeviceController(device_model);

    char evt;
    cout << "Fire event (qQwWhjJkKl) ..." << endl;

    while (cin >> evt) {
        device_controller->handle_event(evt);
    }

    delete device_controller;
    delete device_model;
    return 0;
}
