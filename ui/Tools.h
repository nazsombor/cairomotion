//
// Created by abraham on 8/30/24.
//

#ifndef TOOLS_H
#define TOOLS_H
#include <gtkmm.h>

#include "ColorPicker.h"


class Tools : public Gtk::Box{
public:
    enum Type {PEN, PENCIL, ERASER, SOLID_BRUSH, TEXTURED_BRUSH};
    Type type = PEN;
    Gtk::Box tools_box;
    Gtk::Button pen;
    Gtk::Button pencil;
    Gtk::Button eraser;
    Gtk::Button solid_brush;
    Gtk::Button textured_brush;
    ColorPicker color_picker;

    Tools();

    void select_pen();

    void select_pencil();

    void select_eraser();

    void select_solid_brush();

    void select_textured_brush();
};



#endif //TOOLS_H
