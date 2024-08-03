//
// Created by abris on 7/31/24.
//

#ifndef CAIROMOTION_CENTERCONTAINER_H
#define CAIROMOTION_CENTERCONTAINER_H


#include "Widget.h"

class CenterContainer : public ui::Widget{
    ui::Widget *child;
public:
    int childOptimalWidth = 1920, childOptimalHeight = 1080;
    int cX, cY, cWidth, cHeight;
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    void onStylusDown(double x, double y) override;

    void onStylusMotion(gdouble x, gdouble y) override;

    void onStylusUp(double x, double y) override;

    void onMouseMotion(double x, double y) override;


    void onRightClick(double x, double y) override;

    void setChild(ui::Widget &widget);
};


#endif //CAIROMOTION_CENTERCONTAINER_H
