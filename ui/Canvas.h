//
// Created by abris on 7/31/24.
//

#ifndef CAIROMOTION_CANVAS_H
#define CAIROMOTION_CANVAS_H


#include "Widget.h"

class Canvas : public ui::Widget{
    int canvasWidth = 1920, canvasHeight = 1080;
public:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    void onStylusMotion(gdouble x, gdouble y) override;

    void onRightClick(double x, double y) override;

};


#endif //CAIROMOTION_CANVAS_H
