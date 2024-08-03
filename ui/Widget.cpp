//
// Created by abris on 7/28/24.
//

#include "Widget.h"

void ui::Widget::allocateSize(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void ui::Widget::queueDraw() {
    area->queue_draw();
}


