#include "method_request.h"


Method_Request::Method_Request(){}
Method_Request::~Method_Request(){}
bool Method_Request::operator==(Method_Request const & mr)const {
    cout<<"OP\n";
    // return equals(mr);
}
Put::Put (Message_Queue_Servant *rep, Message arg): servant_ (rep), arg_ (arg) {}
bool Put::guard (void) const {
    // Synchronization constraint.
    cout<<servant_<<"\n";
    return !servant_->full ();
}
void Put::call (void) {
    // Enqueue message into message queue.
    servant_->put (arg_);
}
bool Put::operator==(Put const & p)const{
    return p.arg_ == arg_;
}
// bool Put::equals(Put const & p)const{
//     return p.arg_ == arg_;
// }
    

Get::Get (Message_Queue_Servant *rep, Message_Future &f): servant_ (rep), result_ (f) {}
bool Get::guard (void) const {
    // Synchronization constraint.
    return !servant_->empty ();
    // return true;
}
void Get::call (void) {
    // Bind the dequeued message to the
    // future result object.
    result_.msg_ = servant_->get ();
}
bool Get::operator==(Get const & g)const{
    return true;
}