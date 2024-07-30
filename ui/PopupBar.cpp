//
// Created by abris on 7/28/24.
//

#include "PopupBar.h"

void PopupBar::onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) {

    switch(side) {
        case LEFT:
            break;
        case RIGHT:
            break;
        case TOP:
            break;
        case BOTTOM:
            if (isOpen) {
                cr->set_source_rgb(.8,.8,.8);
                cr->rectangle(0, height - openSize, width, openSize);
                cr->fill_preserve();
                cr->set_source_rgb(.0, .0, .0);
                cr->stroke();
            } else {
                cr->set_source_rgb(.8,.8,.8);
                cr->rectangle(0, height - 60, width, 60);
                cr->fill_preserve();
                cr->set_source_rgb(.0, .0, .0);
                cr->stroke();
            }
            break;
    }

}

void PopupBar::onMouseMotion(gdouble x, gdouble y) {

}
