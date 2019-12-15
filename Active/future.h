#ifndef FUTURE_H
#define FUTURE_H
#include"message.h"
class Message_Future
{
    public:
    Message_Future();
    // Message_Future(Message);
    // ... constructors/destructors, etc.,
    // Type conversion, which blocks
    // waiting to obtain the result of the
    // asynchronous method invocation.
    operator Message();

    // private:
    Message msg_;

};
#endif