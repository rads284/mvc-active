#include "activation_queue.h"

Activation_Queue::Activation_Queue(){}
Activation_Queue::~Activation_Queue(){}
void Activation_Queue::enqueue (Method_Request *method){
    active_queue_.push_back(*method);
}
void Activation_Queue::dequeue (Method_Request *method){
    // std::deque<Method_Request>::iterator iter = active_queue_.begin();
    aq_iter iter = active_queue_.begin();
    while(iter!= active_queue_.end()){
        (*iter == *method) ? iter = active_queue_.erase(iter) : ++iter;
    }
}
 aq_iter Activation_Queue::begin(){
    return active_queue_.begin();
}
aq_iter Activation_Queue::end(){
    return active_queue_.end();
}