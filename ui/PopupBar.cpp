//
// Created by abris on 7/28/24.
//

#include "PopupBar.h"

void PopupBar::onDraw(const Cairo::RefPtr<Cairo::Context> &cr) {

    switch(side) {
        case LEFT:
            if (hidden) {
                drawSpaceChild(cr, x, y, width, height);
            } else {
                if (isOpen) {
                    drawBar(cr, x, y, openSize, height);
                    drawSpaceChild(cr, x + openSize, y, width - openSize, height);
                } else {
                    drawBar(cr, x, y, closedSize, height);
                    drawSpaceChild(cr, x + closedSize, y, width - closedSize, height);
                }
            }
            break;
        case RIGHT:
            break;
        case TOP:
            break;
        case BOTTOM:
            if (hidden) {
                drawSpaceChild(cr, x, y, width, height);
            } else {
                if (isOpen) {
                    drawBar(cr, x, height - openSize, width, openSize);
                    drawSpaceChild(cr, x, y, width, height - openSize);
                } else {
                    drawBar(cr, x, height - closedSize, width, closedSize);
                    drawSpaceChild(cr, x, y, width, height - closedSize);
                }
            }
            break;
    }

}

void PopupBar::drawSpaceChild(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height) {
    if (spaceChild) {
        spaceChild->allocateSize(x, y, width, height);
        spaceChild->onDraw(cr);
    }
}

void PopupBar::drawBar(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height) const {
    cr->set_source_rgb(.8, .8, .8);
    cr->rectangle(x, y, width, height);
    cr->fill_preserve();
    cr->set_source_rgb(.0, .0, .0);
    cr->stroke();
}

void PopupBar::onStylusDown(double x, double y) {
    if (barContains(x, y)) {

    } else if (spaceChildContains(x, y)) {
        if (spaceChild) {
            spaceChild->onStylusDown(x, y);
        }
    }
}

void PopupBar::onStylusMotion(gdouble pointerX, gdouble pointerY) {
    if (barContains(pointerX, pointerY)) {
        if (!isOpen) {
            queueDraw();
        }
        isOpen = true;
    } else if (spaceChildContains(pointerX, pointerY)){
        if (isOpen) {
            queueDraw();
        }
        isOpen = false;
        if (spaceChild)
            spaceChild->onStylusMotion(pointerX, pointerY);
    }
}

void PopupBar::onStylusUp(double x, double y) {
    if (barContains(x, y)) {

    } else if (spaceChildContains(x, y)) {
        if (spaceChild) {
            spaceChild->onStylusUp(x, y);
        }
    }
}

bool PopupBar::barContains(gdouble pointerX, gdouble pointerY) {
    if (hidden) {
        return false;
    }

    int size = isOpen ? openSize : closedSize;
    switch(side) {
        case LEFT:
            return (pointerX > x && pointerX < x + size) && (pointerY > y && pointerY < y + height);
        case RIGHT:
            break;
        case TOP:
            break;
        case BOTTOM:
            return (pointerX > x && pointerX < x + width) && (pointerY > y + height - size && pointerY < y + height);
    }
    return false;
}

void PopupBar::setSpaceChild(ui::Widget &child) {
    spaceChild = &child;
    spaceChild->area = area;

}

void PopupBar::onRightClick(double x, double y) {
    if (toggleHidBarOnRightClick) {
        hidden = !hidden;
        if (dynamic_cast<PopupBar*>(spaceChild) != nullptr) {
            spaceChild->onRightClick(x, y);
        }
        queueDraw();
    }
}

bool PopupBar::spaceChildContains(gdouble pointerX, gdouble pointerY) {
    if (hidden) {
        return true;
    }

    int size = isOpen ? openSize : closedSize;
    switch(side) {
        case LEFT:
            return (pointerX > x + size && pointerX < x + width) && (pointerY > y && pointerY < y + height);
        case RIGHT:
            break;
        case TOP:
            break;
        case BOTTOM:
            return (pointerX > x && pointerX < x + width) && (pointerY > y && pointerY < y + height - size);
    }
    return false;
}

void PopupBar::onMouseMotion(double pointerX, double pointerY) {
    if (barContains(pointerX, pointerY)) {
        if (!isOpen) {
            queueDraw();
        }
        isOpen = true;
    } else if (spaceChildContains(pointerX, pointerY)){
        if (isOpen) {
            queueDraw();
        }
        isOpen = false;
        if (spaceChild)
            spaceChild->onMouseMotion(pointerX, pointerY);
    }
}
