/*
*/
#ifndef MODEL_HPP
#define MODEL_HPP

#include "view.hpp"
#include <cstddef>

using namespace std;

class Model {
public:
    virtual ~Model();
    void attach_observer(View*);
    void detach_observer(View*);
    void notify_observers();
protected:
    Model();
    static const size_t MaxObservers = 1;
private:
    View * _observer[MaxObservers];
    size_t _number_observers;
};

#endif
