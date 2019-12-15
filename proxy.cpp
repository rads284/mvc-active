#include "proxy.h"
#include<iostream>
using namespace std;
Message_Queue_Proxy::Message_Queue_Proxy(int size = MAX_SIZE){
    cout<<"Message Queue Proxy Created\n";
    Message_Queue_Servant *servant_ = new Message_Queue_Servant(size);
    MQ_Scheduler *scheduler_ = new MQ_Scheduler();
}
// Message_Queue_Proxy::~Message_Queue_Proxy(){}
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
