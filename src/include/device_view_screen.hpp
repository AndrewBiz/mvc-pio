/*
*/
#ifndef DEVICE_VIEW_SCREEN_HPP
#define DEVICE_VIEW_SCREEN_HPP

#include "view.hpp"
#include "device_model.hpp"

class DeviceViewScreen : public View {
public:
    DeviceViewScreen(DeviceModel*);
    virtual ~DeviceViewScreen();
    virtual void update();
    void draw_screen();
protected:
    static const size_t ScrBufSize = 17; // like real LCD 16 char wide
private:
    DeviceModel * _model;
    char _scr_buf1[ScrBufSize]; // screen Line1
    char _scr_buf2[ScrBufSize]; // screen Line2
};

#endif
