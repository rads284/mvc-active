#include"method_request.h"
#include"activation_queue.h"

class MQ_Scheduler
{
    public:
    // ... constructors/destructors, etc.,
    // Insert the Method Request into
    // the Activation_Queue. This method
    // runs in the thread of its caller.
    void enqueue (Method_Request *method);
    // Dispatch the Method Requests
    // on their Servant. This method
    // runs in a separate thread.
    virtual void dispatch (void);
    protected:
    // Queue of pending Method_Requests.
    Activation_Queue *act_que_;
};