//
// Created by abris on 8/1/24.
//

#ifndef CAIROMOTION_CANVAS_H
#define CAIROMOTION_CANVAS_H


#include "Widget.h"
#include "../thirdparty/ink-stroke-modeler/ink_stroke_modeler/stroke_modeler.h"
#include "../thirdparty/ink-stroke-modeler/ink_stroke_modeler/types.h"
#include "../thirdparty/ink-stroke-modeler/ink_stroke_modeler/params.h"
#include "../Drawings.h"

class Canvas : public ui::Widget{
    bool isStylusDown = false;

public:
    ink::stroke_model::StrokeModelParams params;
    ink::stroke_model::StrokeModeler modeler;
    std::chrono::milliseconds time;
    std::vector<ink::stroke_model::Result> smoothedStroke;

    int canvasWidth = 1920, canvasHeight = 1080;

    Canvas();

    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    void onStylusDown(double x, double y) override;

    void onStylusMotion(gdouble x, gdouble y) override;

    void onStylusUp(double x, double y) override;

    void onRightClick(double x, double y) override;

    void onMouseMotion(double x, double y) override;
    Glib::RefPtr<Gtk::GestureStylus> *gestureStylus;
    Drawings *drawings;
};


#endif //CAIROMOTION_CANVAS_H
