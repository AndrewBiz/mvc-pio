/*
*/
#include "include/device_controller.hpp"
#include <iostream>

using namespace std;

DeviceController::DeviceController(DeviceModel * m) :
    _model(m),
    _screen(new DeviceViewScreen(_model))
{
    cout << "DeviceController constructor triggered" << endl;
    // _screen - welcome message
    _model->initialize();
}

DeviceController::~DeviceController() {
    cout << "DeviceController ~destructor triggered" << endl;
    delete _screen;
}

void DeviceController::handle_event(char evt) {
    switch (evt) {
    case 'q':
        save_to_memory(1);
        break;
    case 'w':
        save_to_memory(2);
        break;
    case 'Q':
        load_from_memory(1);
        break;
    case 'W':
        load_from_memory(2);
        break;
    default:
        cout << "UNKNOWN EVENT: " << evt << endl;
        break;
    }
};

void DeviceController::change_value(int steps) {

};

void DeviceController::next_step_level() {

};

void DeviceController::prev_step_level() {

};

void DeviceController::save_to_memory(int memory_slot) {
    cout << "DeviceController::save_to_memory - saving to slot " << memory_slot << endl;
};

void DeviceController::load_from_memory(int memory_slot) {
    cout << "DeviceController::load_to_memory - loading from slot " << memory_slot << endl;
};
