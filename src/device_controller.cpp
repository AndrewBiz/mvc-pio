/*
*/
#include "include/device_controller.hpp"
#include "include/device_state_normal.hpp"
#include "include/device_state_direct.hpp"
#include "include/device_state_calibrate.hpp"
#include <iostream>

using namespace std;

DeviceController::DeviceController(DeviceModel * m) :
    _model(m),
    _screen(new DeviceViewScreen(_model)),
    _state(new DeviceStateNormal(_model))
{
    cout << "DeviceController constructor triggered" << endl;
    // _screen - welcome message
    _model->initialize();
    _screen->change_state_to(State::Normal);
}

DeviceController::~DeviceController() {
    cout << "DeviceController ~destructor triggered" << endl;
    delete _screen;
    delete _state;
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
        _state->change_value(-1);
        break;
    case 'J':  //down
        _state->change_value(-5);
        break;
    case 'k':  //up
        _state->change_value(1);
        break;
    case 'K':  //up
        _state->change_value(5);
        break;
    case 'h':  //prev step
        _state->prev_step_level();
        break;
    case 'l':  //next step
        _state->next_step_level();
        break;
    case 's':  //change state - click
        change_state_to(_state->click_change_state());
        break;
    case 'S':  //change state - long click
        change_state_to(_state->long_click_change_state());
        break;
    default:
        cout << "UNKNOWN EVENT: " << evt << endl;
        break;
    }
}

void DeviceController::change_state_to(State new_state) {
    cout << "DeviceController::change_state_to " << int(new_state) << " triggered" << endl;
    switch (new_state) {
    case State::Direct:
        delete _state;
        _state = new DeviceStateDirect(_model);
        break;
    case State::Calibration:
        delete _state;
        _state = new DeviceStateCalibrate(_model);
        break;
    case State::Normal:
        delete _state;
        _state = new DeviceStateNormal(_model);
        break;
    default:
        break;
    }
    _screen->change_state_to(new_state);
}
