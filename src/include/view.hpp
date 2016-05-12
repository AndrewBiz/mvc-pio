/*
*/
#ifndef VIEW_HPP
#define VIEW_HPP

class View {
public:
    virtual ~View() = default;
    virtual void update() = 0; //pure virtual function

protected:
    View() = default; //default constructor
};

#endif
