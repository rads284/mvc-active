#include"model.h"

Model::Model(const string &data) {
    this->SetData(data);
}
Model::Model() { } // default constructor
string Model::Data(){
    return this->data;
}

void Model::SetData(const string &data) {
    this->data = data;
    if (this->event != nullptr) { // data change callback event
        this->event(data);
    }   
}
//  register the event when data changes.
void Model::RegisterDataChangeHandler(DataChangeHandler handler) {
    this->event = handler;
}