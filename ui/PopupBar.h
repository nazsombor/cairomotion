//
// Created by abris on 7/28/24.
//

#ifndef CAIROUI_POPUPBAR_H
#define CAIROUI_POPUPBAR_H


#include "Widget.h"

class PopupBar : public ui::Widget {
    bool isOpen = false;
public:

    enum Side {LEFT, RIGHT, TOP, BOTTOM};
    Side side = BOTTOM;
    int openSize = 300;
    int barX, barY, barWidth, barHeight;

public:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) override;

    void onMouseMotion(gdouble x, gdouble y) override;
};


#endif //CAIROUI_POPUPBAR_H
