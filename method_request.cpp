#include "method_request.h"


Method_Request::Method_Request(){}
Method_Request::~Method_Request(){}
Put::Put (Message_Queue_Servant *rep, Message arg): servant_ (rep), arg_ (arg) {}
bool Put::guard (void) const {
    // Synchronization constraint.
    return !servant_->full ();
}
void Put::call (void) {
    // Enqueue message into message queue.
    servant_->put (arg_);
}
    

Get::Get (Message_Queue_Servant *rep, Message_Future &f): servant_ (rep), result_ (f) {}
bool Get::guard (void) const {
    // Synchronization constraint.
    return !servant_->empty ();
}
void Get::call (void) {
    // Bind the dequeued message to the
    // future result object.
    // result_ = servant_->get ();
}