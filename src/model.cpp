/*
*/
#include "include/model.hpp"
#include <iostream>

using namespace std;

Model::Model() :
    _number_observers(0)
{
    for (size_t i = 0; i < MaxObservers; i++) {
        _observer[i] = nullptr;
    };
    cout << "Model constructor triggered" << endl;
}

Model::~Model() {
    for (size_t i = 0; i < MaxObservers; i++) {
        _observer[i] = nullptr;
    };
    cout << "Model ~destructor triggered" << endl;
}

void Model::attach_observer(View * v) {
    cout << "Model::attach_observer triggered" << endl;
    if (_number_observers < MaxObservers) {
        _observer[_number_observers++] = v;
    };
    cout << ".... _number_observers = " << _number_observers << endl;
}

void Model::detach_observer(View * v) {
    cout << "Model::detach_observer triggered" << endl;
    if (_number_observers > 0) {
        _observer[--_number_observers] = nullptr;
    };
    cout << ".... _number_observers = " << _number_observers << endl;
}

void Model::notify_observers() {
    cout << "Model::notify_observers triggered" << endl;
    for (size_t i = 0; i < MaxObservers; i++) {
        if (_observer[i] != nullptr) _observer[i]->update();
    };
}
