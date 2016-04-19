/*
*/
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller {
public:
    virtual ~Controller() = default;
    virtual void change_value(int steps) = 0; //pure virtual function
    virtual void next_step_level() = 0; //pure virtual function
    virtual void prev_step_level() = 0; //pure virtual function
    virtual void save_to_memory(int memory_slot) = 0; //pure virtual function
    virtual void load_from_memory(int memory_slot) = 0; //pure virtual function

protected:
    Controller() = default; //default constructor
};

#endif
