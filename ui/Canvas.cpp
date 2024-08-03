//
// Created by abris on 8/1/24.
//

#include "Canvas.h"

void Canvas::onDraw(const Cairo::RefPtr<Cairo::Context> &cr) {
    drawings->onDraw(cr, x, y, width, height);
}

Canvas::Canvas() {
    params.wobble_smoother_params.timeout = ink::stroke_model::Duration{.04};
    params.wobble_smoother_params.speed_floor = 1.31;
    params.wobble_smoother_params.speed_ceiling = 1.44;
    params.position_modeler_params.spring_mass_constant = 11.f / 32400;
    params.position_modeler_params.drag_constant = 72.f;
    params.sampling_params.min_output_rate = 500;
    params.sampling_params.end_of_stroke_stopping_distance = .001;
    params.sampling_params.end_of_stroke_max_iterations = 20;
    params.stylus_state_modeler_params.max_input_samples = 20;
    params.prediction_params = ink::stroke_model::StrokeEndPredictorParams();

    modeler.Reset(params);
}

void Canvas::onStylusDown(double x, double y) {
    modeler.Reset();

    smoothedStroke.clear();

    time = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );

    ink::stroke_model::Input input;
    auto correctedX = ((float) x - this->x) / (width / 1920.0f);
    auto correctedY = ((float) y - this->y) / (height / 1080.0f);
    input.position = {correctedX, correctedY};
    input.event_type = ink::stroke_model::Input::EventType::kDown;
    input.time = ink::stroke_model::Time{0};
    input.pressure = (*gestureStylus)->get_axis(Gdk::AxisUse::PRESSURE).value();
    input.orientation = M_PI;
    input.tilt = 0;

    modeler.Update(input, smoothedStroke);
    drawings->pen(smoothedStroke);
    queueDraw();
}

void Canvas::onStylusMotion(gdouble x, gdouble y) {
    auto duration = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    auto delta = duration - time;
    auto t = delta.count() / 1000.0;

    ink::stroke_model::Input input;

    input.event_type = ink::stroke_model::Input::EventType::kMove;
    auto correctedX = ((float) x - this->x) / (width / 1920.0f);
    auto correctedY = ((float) y - this->y) / (height / 1080.0f);
    input.position = {correctedX, correctedY};input.time = ink::stroke_model::Time{(double) t};
    input.pressure = (*gestureStylus)->get_axis(Gdk::AxisUse::PRESSURE).value();
    input.orientation = M_PI;
    input.tilt = 0;

    modeler.Update(input, smoothedStroke);
    drawings->pen(smoothedStroke);
    queueDraw();
}

void Canvas::onStylusUp(double x, double y) {
    auto duration = duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()
    );
    auto delta = duration - time;
    auto t = delta.count() / 1000.0;

    ink::stroke_model::Input input;

    input.event_type = ink::stroke_model::Input::EventType::kUp;
    auto correctedX = ((float) x - this->x) / (width / 1920.0f);
    auto correctedY = ((float) y - this->y) / (height / 1080.0f);
    input.position = {correctedX, correctedY};input.time = ink::stroke_model::Time{(double) t};
    input.pressure = (*gestureStylus)->get_axis(Gdk::AxisUse::PRESSURE).value();
    input.orientation = M_PI;
    input.tilt = 0;

    modeler.Update(input, smoothedStroke);
    drawings->pen(smoothedStroke);
    queueDraw();
}

void Canvas::onRightClick(double x, double y) {

}

void Canvas::onMouseMotion(double x, double y) {

}
