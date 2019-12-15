// view.h
// https://helloacm.com/model-view-controller-explained-in-c/
#pragma once
#include <iostream>                  
#include "model.h"                                               
// View is responsible to present data to users
class View {
    public:
        View(const Model &model);
        View();
        void SetModel(const Model &model);
        void Render();
    private:
        Model model;
};