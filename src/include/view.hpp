/*
*/
#ifndef VIEW_HPP
#define VIEW_HPP

class Model;  // forward decraration

class View {
public:
    virtual ~View() = default;
    virtual void update() = 0; //pure virtual function

protected:
    View() = default; //default constructor
};

#endif
