#ifndef PROXY_H
#define PROXY_H
#include "method_request.h"
#include "future.h"
#include "servant.h"
#include "scheduler.h"


class Message_Queue_Proxy
{
    public:
    // Bound the message queue size.
    // enum { MAX_SIZE = 100 };
    Message_Queue_Proxy(int);
    // Schedule <put> to run as an active object.
    void put (const Message m);
    // Return a Message_Future as the ‘‘future’’
    // result of an asynchronous <get>
    // method on the active object.
    Message_Future get (void);
    // These predicates can execute directly
    // since they are "const".
    bool empty (void) const ;
    bool full (void) const ;
    protected:
    // The Servant that implements the
    // Active Object methods.
    Message_Queue_Servant *servant_;
    // A scheduler for the Message Queue.
    MQ_Scheduler *scheduler_;
};
#endif