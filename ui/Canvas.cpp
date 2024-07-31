//
// Created by abris on 7/31/24.
//

#include "Canvas.h"

void Canvas::onDraw(const Cairo::RefPtr<Cairo::Context> &cr) {
    std::cout << width << " " << height << std::endl;
    cr->set_source_rgb(.9, .9, .9);
    cr->rectangle(x, y, width, height);
    cr->fill();

    double cX = x, cY = y, cWidth = canvasWidth, cHeight = canvasHeight;

    double cR = (double) width / canvasWidth;

    cWidth *= cR;
    cHeight *= cR;

    if (cHeight > height) {
        cR = (double) height / canvasHeight;
    }

    cWidth = canvasWidth * cR;
    cHeight = canvasHeight * cR;

    cX = x + (width - cWidth) / 2;
    cY = y + (height - cHeight) / 2;

    cr->set_source_rgb(1, 1, 1);
    cr->rectangle(cX, cY, cWidth, cHeight);
    cr->fill();

}

void Canvas::onStylusMotion(gdouble x, gdouble y) {

}

void Canvas::onRightClick(double x, double y) {

}
