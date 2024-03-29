#include "activation_queue.h"
using namespace std;    
Activation_Queue::Activation_Queue(){
    cout<<"Activation Queue Created Size:" << active_queue_.size()<<"\n";
}
void Activation_Queue::enqueue (Method_Request *method){
    // cout<<"Activation queue Enqueueing\n";
    active_queue_.push_back(method);
    cout<<"Size is: "<<active_queue_.size()<<"\n";
}
aq_iter Activation_Queue::dequeue (Method_Request *method){
    cout<<"Activation queue Dequeueing\n";
    aq_iter iter = find(active_queue_.begin(), active_queue_.end(), method);
    aq_iter iter2 = active_queue_.end();
    if(iter != active_queue_.end()){
        iter2 = active_queue_.erase(iter);
    }
    return iter2;
    // aq_iter iter = active_queue_.begin();
    // while(iter!= active_queue_.end()){
    //     // cout<<(**iter == *method)<<"DEQUE \n";
    //     (**iter == *method) ? iter = active_queue_.erase(iter) : ++iter;
    // }
}
aq_iter Activation_Queue::begin(){
    // cout<<"Begin:"<<this<<"\n";
    return active_queue_.begin();
}
aq_iter Activation_Queue::end(){
    // cout<<"End:"<<this<<"\n";
    return active_queue_.end();
}