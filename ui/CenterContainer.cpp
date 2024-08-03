//
// Created by abris on 7/31/24.
//

#include "CenterContainer.h"

void CenterContainer::onDraw(const Cairo::RefPtr<Cairo::Context> &cr) {
    cr->set_source_rgb(.9, .9, .9);
    cr->rectangle(x, y, width, height);
    cr->fill();

    cX = x, cY = y, cWidth = childOptimalWidth, cHeight = childOptimalHeight;

    double cR = (double) width / childOptimalWidth;

    cWidth *= cR;
    cHeight *= cR;

    if (cHeight > height) {
        cR = (double) height / childOptimalHeight;
    }

    cWidth = childOptimalWidth * cR;
    cHeight = childOptimalHeight * cR;

    cX = x + (width - cWidth) / 2;
    cY = y + (height - cHeight) / 2;

    cr->set_source_rgb(1, 1, 1);
    cr->rectangle(cX, cY, cWidth, cHeight);
    cr->fill();

    child->allocateSize(cX, cY, cWidth, cHeight);
    child->onDraw(cr);

}

void CenterContainer::onStylusMotion(gdouble x, gdouble y) {
    if (x > cX && x < cX + cWidth && y > cY && y < cY + cHeight) {
        child->onStylusMotion(x, y);
    }
}

void CenterContainer::onRightClick(double x, double y) {

}

void CenterContainer::setChild(ui::Widget &widget) {
    child = &widget;
    child->area = area;
}

void CenterContainer::onStylusDown(double x, double y) {
    if (x > cX && x < cX + cWidth && y > cY && y < cY + cHeight) {
        child->onStylusDown(x, y);
    }
}

void CenterContainer::onStylusUp(double x, double y) {
    if (x > cX && x < cX + cWidth && y > cY && y < cY + cHeight) {
        child->onStylusUp(x, y);
    }
}

void CenterContainer::onMouseMotion(double x, double y) {
    child->onMouseMotion(x, y);
}
