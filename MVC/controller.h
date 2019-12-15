#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "model.h"
#include "view.h"

// Controller combines Model and View
class Controller {
    public:
        Controller(const Model &model, const View &view);
        void SetModel(const Model &model);
        void SetView(const View &view) ;
        void OnLoad();
    private:
        Model model;
        View view;
};
#endif