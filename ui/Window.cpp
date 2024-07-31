//
// Created by abris on 7/30/24.
//

#include "Window.h"

ui::Window::Window(std::string title, int width, int height) {
    set_title(std::move(title));
    set_default_size(width, height);
    set_child(area);
    //set_cursor("none");

    auto eventControllerKey = Gtk::EventControllerKey::create();
    eventControllerKey->signal_key_released().connect(sigc::mem_fun(*this, &Window::onKeyRelease));
    add_controller(eventControllerKey);

    auto gestureStylus = Gtk::GestureStylus::create();
    gestureStylus = Gtk::GestureStylus::create();
    gestureStylus->signal_down().connect(sigc::mem_fun(*this, &Window::onStylusDown));
    gestureStylus->signal_motion().connect(sigc::mem_fun(*this, &Window::onStylusMotion));
    gestureStylus->signal_up().connect(sigc::mem_fun(*this, &Window::onStylusUp));

    auto eventControllerMotion = Gtk::EventControllerMotion::create();
    eventControllerMotion->signal_motion().connect(sigc::mem_fun(*this, &Window::onStylusMotion));

    auto gestureClick = Gtk::GestureClick::create();

    gestureClick->signal_released().connect(sigc::mem_fun(*this, &Window::onRightClick));
    gestureClick->set_button(3);

    area.add_controller(gestureStylus);
    area.add_controller(eventControllerMotion);
    area.add_controller(gestureClick);
    area.set_draw_func(sigc::mem_fun(*this, &Window::onDraw));
}

void ui::Window::onKeyRelease(gint key, gint _, Gdk::ModifierType modifierType) {
    std::cout << key << std::endl;
    if (fullscreenEnabledOnKey && key == fullscreenKey) {
        if (isFullscreen) {
            unfullscreen();
            isFullscreen = false;
        } else {
            fullscreen();
            isFullscreen = true;
        }
    }
}

void ui::Window::onDraw(const Cairo::RefPtr<Cairo::Context> &cr, int width, int height) {
    child->allocateSize(0, 0, width, height);
    child->onDraw(cr);
}

void ui::Window::onStylusDown(double x, double y) {

}

void ui::Window::onStylusMotion(double x, double y) {
    child->onStylusMotion(x, y);
}

void ui::Window::onStylusUp(double x, double y) {

}

void ui::Window::enableFullscreenOnKey(int key) {
    fullscreenKey = key;
    fullscreenEnabledOnKey = true;
}

void ui::Window::setChild(ui::Widget &widget) {
    child = &widget;
    child->area = &area;
}

void ui::Window::onRightClick(int type, double x, double y) {
    child->onRightClick(x, y);
}
