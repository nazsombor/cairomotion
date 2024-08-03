//
// Created by abris on 8/1/24.
//

#include "Drawings.h"

Drawings::Drawings() {
    surface = Cairo::ImageSurface::create(Cairo::Surface::Format::ARGB32, 1920, 1080);
}

void Drawings::onDraw(const std::shared_ptr<Cairo::Context> &cr, int x, int y, int width, int height) {
    cr->set_source(surface, x, y);
    cr->rectangle(x, y, width, height);
    cr->fill();
}

void Drawings::pen(std::vector<ink::stroke_model::Result> &stroke) {
    auto cr = Cairo::Context::create(surface);

    for (int i = 1; i < stroke.size(); i++) {
        auto a = stroke[i - 1];
        auto b = stroke[i];
        double dX = (b.position.x - a.position.x) / 5;
        double dY = (b.position.y - a.position.y) / 5;
        double dP = (b.pressure - a.pressure) / 5;

        for (int j = 0; j < 5; j++) {
            cr->arc( a.position.x + j * dX, a.position.y + j * dY, (a.pressure + j * dP) * 5, 0, 2 * M_PI);
            cr->fill();
        }
    }
}
