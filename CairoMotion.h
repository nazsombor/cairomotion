//
// Created by abris on 7/27/24.
//

#ifndef CAIROMOTION_CAIROMOTION_H
#define CAIROMOTION_CAIROMOTION_H


#include "ui/PopupBar.h"
#include "ui/Window.h"

class CairoMotion : public ui::Window {
    PopupBar timelinePopupBar;
    PopupBar toolsPopupBar;
public:
    CairoMotion();

};


#endif //CAIROMOTION_CAIROMOTION_H
