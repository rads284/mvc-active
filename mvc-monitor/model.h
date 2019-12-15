#ifndef MODEL_H
#define MODEL_H

#include <string>
using namespace std;
#include "common.h"
// Model is responsible for data get and set
class Model {
    public:
        Model(const string &data) ;
        Model();
        string Data();

        void SetData(const string &data);
        //  register the event when data changes.
        void RegisterDataChangeHandler(DataChangeHandler handler);
    private:
        string data = "";
        DataChangeHandler event = nullptr;
};
#endif