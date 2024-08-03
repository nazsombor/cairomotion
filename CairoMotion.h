//
// Created by abris on 7/27/24.
//

#ifndef CAIROMOTION_CAIROMOTION_H
#define CAIROMOTION_CAIROMOTION_H


#include "ui/PopupBar.h"
#include "ui/Window.h"
#include "ui/CenterContainer.h"
#include "ui/Canvas.h"
#include "Drawings.h"

class CairoMotion : public ui::Window {
    PopupBar timelinePopupBar;
    PopupBar toolsPopupBar;
    CenterContainer canvasCenterContainer;
    Canvas canvas;
    Drawings drawings;
public:
    CairoMotion();

};


#endif //CAIROMOTION_CAIROMOTION_H
