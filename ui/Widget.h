//
// Created by abris on 7/28/24.
//

#ifndef CAIROUI_WIDGET_H
#define CAIROUI_WIDGET_H


#include <gtkmm.h>
#include <iostream>

namespace ui {
    class Widget {
    public:
        Gtk::DrawingArea *area;

        virtual void onDraw(const Cairo::RefPtr<Cairo::Context> &cr) = 0;

        virtual void onStylusMotion(gdouble x, gdouble y) = 0;

        void allocateSize(int x, int y, int width, int height);

        void queueDraw();

    protected:
        int x = 0, y = 0, width = 0, height = 0;
    };
}




#endif //CAIROUI_WIDGET_H
