//
// Created by abris on 7/27/24.
//

#include "CairoMotion.h"

CairoMotion::CairoMotion() : ui::Window("Cairo Motion", 1600, 900) {
    enableFullscreenOnKey(65480); //F11
    setChild(timelinePopupBar);

    timelinePopupBar.side = PopupBar::Side::BOTTOM;
    timelinePopupBar.openSize = 600;
    timelinePopupBar.setSpaceChild(toolsPopupBar);

    toolsPopupBar.side = PopupBar::Side::LEFT;
    toolsPopupBar.openSize = 500;
    toolsPopupBar.setSpaceChild(canvas);

}


