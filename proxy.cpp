#include "proxy.h"
#include<iostream>
Message_Queue_Proxy::Message_Queue_Proxy(int size):servant_(new Message_Queue_Servant(size)),
scheduler_(new MQ_Scheduler()),dispatcher_(&MQ_Scheduler::dispatch, scheduler_){
    cout<<"Message Queue Proxy Created\n";
    cout<<"Constructor"<<"\n";
}
Message_Queue_Proxy::~Message_Queue_Proxy(){
    cout <<"Gonna JOIN Thread \n ";
    dispatcher_.join();
}
void Message_Queue_Proxy::put (const Message m) {
    cout<<"Message Recieved\n";
    Method_Request *method = new Put (servant_, m);
    cout<<"Method Request Created\n";
    scheduler_->enqueue (method);
}
// Return a Message_Future as the ‘‘future’’
// result of an asynchronous <get>
// method on the active object.
Message_Future Message_Queue_Proxy::get (void) {
    Message_Future result;
    Method_Request *method = new Get (servant_, result);
    scheduler_->enqueue (method);
    return result;
}
// These predicates can execute directly
// since they are "const".
bool Message_Queue_Proxy::empty (void) const {
    return servant_->empty ();
}
bool Message_Queue_Proxy::full (void) const {
    return servant_->full ();
}
// void Message_Queue_Proxy::run_dispatcher(void){
//     thread dispatcher_(scheduler_->dispatch);
// }