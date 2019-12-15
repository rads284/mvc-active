#ifndef SCHEDULER_H
#define SCHEDULER_H
#include"method_request.h"
#include"activation_queue.h"
#include<iostream>
#include<deque>
using namespace std;
class MQ_Scheduler
{
    public:
    MQ_Scheduler();
    ~MQ_Scheduler();
    // ... constructors/destructors, etc.,
    // Insert the Method Request into
    // the Activation_Queue. This method
    // runs in the thread of its caller.
    void enqueue (Method_Request *method);
    // Dispatch the Method Requests
    // on their Servant. This method
    // runs in a separate thread.
    void dispatch (void);
    // void dequeue (Method_Request *method)
    private:
    // Queue of pending Method_Requests.
    Activation_Queue *act_que_;
};
#endif