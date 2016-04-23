/*
*/
#include "include/device_controller.hpp"
#include "include/device_state_normal.hpp"
#include <iostream>

using namespace std;

DeviceController::DeviceController(DeviceModel * m) :
    _model(m),
    _screen(new DeviceViewScreen(_model)),
    _state(new DeviceStateNormal(this))
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
        _state->save_to_memory(1);
        break;
    case 'w':
        _state->save_to_memory(2);
        break;
    case 'Q':
        _state->load_from_memory(1);
        break;
    case 'W':
        _state->load_from_memory(2);
        break;
    case 'j':  //down
        change_value(-1);
        break;
    case 'J':  //down
        change_value(-5);
        break;
    case 'k':  //up
        change_value(1);
        break;
    case 'K':  //up
        change_value(5);
        break;
    case 'h':  //prev step
        prev_step_level();
        break;
    case 'l':  //next step
        next_step_level();
        break;
    default:
        cout << "UNKNOWN EVENT: " << evt << endl;
        break;
    }
};

void DeviceController::change_value(int8_t steps) {
    _model->change_value(steps);
};

void DeviceController::next_step_level() {
    _model->next_step_level();
};

void DeviceController::prev_step_level() {
    _model->prev_step_level();
};
