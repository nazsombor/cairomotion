//
// Created by abris on 7/28/24.
//

#ifndef CAIROUI_WIDGET_H
#define CAIROUI_WIDGET_H


#include <gtkmm.h>

namespace ui {
    class Widget {

    public:
        virtual void onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) = 0;

        virtual void onMouseMotion(gdouble x, gdouble y) = 0;
    };
}




#endif //CAIROUI_WIDGET_H
