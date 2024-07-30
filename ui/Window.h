//
// Created by abris on 7/30/24.
//

#ifndef CAIROMOTION_WINDOW_H
#define CAIROMOTION_WINDOW_H


#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <iostream>
#include "Widget.h"

namespace ui {
    class Window : public Gtk::Window {
        Gtk::DrawingArea area;

        bool fullscreenEnabledOnKey = false;
        guint fullscreenKey;

        bool isFullscreen = false;

        ui::Widget *child;

    public:
        Window(std::string title, int width, int height);

        void onKeyRelease(gint key, gint _, Gdk::ModifierType modifierType);

        void onDraw(const Cairo::RefPtr <Cairo::Context> &cr, int width, int height);

        void onStylusDown(double x, double y);

        void onStylusMotion(double x, double y);

        void onStylusUp(double x, double y);

        void enableFullscreenOnKey(int key);

        void setChild(ui::Widget &widget);
    };
}


#endif //CAIROMOTION_WINDOW_H
