#include"view.h"

View::View(const Model &model) {
    this->model = model;
}
View::View() {}
void View::SetModel(const Model &model) {
    this->model = model;
}
void View::Render() {
    std::cout << "Model Data = " << model.Data() << endl;
}