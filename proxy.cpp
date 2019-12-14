#include "method_request.h"
#include "future.h"
#include "servant.h"

class Message_Queue_Proxy
{
    public:
    // Bound the message queue size.
    enum { MAX_SIZE = 100 };
    Message_Queue_Proxy(size_t size = MAX_SIZE) {
        scheduler_ = new MQ_Scheduler;
        servant_ = new Message_Queue_Servant (size);
    }
    // Schedule <put> to run as an active object.
    void put (const Message m) {
        Method_Request *method =new Put (servant_, m);
        scheduler_->enqueue (method);
    }
    // Return a Message_Future as the ‘‘future’’
    // result of an asynchronous <get>
    // method on the active object.
    Message_Future get (void) {
        Message_Future result;
        Method_Request *method = new Get (servant_, result);
        scheduler_->enqueue (method);
        return result;
    }
    // These predicates can execute directly
    // since they are "const".
    bool empty (void) const {
        return servant_->empty ();
    }
    bool full (void) const {
        return servant_->full ();
    }
    protected:
    // The Servant that implements the
    // Active Object methods.
    Message_Queue_Servant *servant_;
    // A scheduler for the Message Queue.
    MQ_Scheduler *scheduler_;
};