//
// Created by abris on 8/1/24.
//

#ifndef CAIROMOTION_DRAWINGS_H
#define CAIROMOTION_DRAWINGS_H

#include <memory>
#include <gtkmm.h>
#include "thirdparty/ink-stroke-modeler/ink_stroke_modeler/types.h"

class Drawings {
public:
    Cairo::RefPtr<Cairo::ImageSurface> surface;


    Drawings();

    void onDraw(const std::shared_ptr<Cairo::Context> &cr, int x, int y, int width, int height);

    void pen(std::vector<ink::stroke_model::Result> &stroke);
};


#endif //CAIROMOTION_DRAWINGS_H
