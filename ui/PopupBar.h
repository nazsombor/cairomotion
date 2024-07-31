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
    int closedSize = 30;

    bool toggleHidBarOnRightClick = true;
    bool hidden = false;

public:
    void onDraw(const Cairo::RefPtr<Cairo::Context> &cr) override;

    void onStylusMotion(gdouble x, gdouble y) override;

    ui::Widget *spaceChild = nullptr;
    ui::Widget *barChild = nullptr;

    void drawBar(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height) const;

    void drawSpaceChild(const Cairo::RefPtr<Cairo::Context> &cr, int x, int y, int width, int height);

    bool barContains(gdouble pointerX, gdouble pointerY);

    void setSpaceChild(ui::Widget &child);

    void onRightClick(double x, double y) override;
};


#endif //CAIROUI_POPUPBAR_H
