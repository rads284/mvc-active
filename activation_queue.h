#include"method_request.h"
class Activation_Queue
{
    public:
    // typedef ... iterator;
    // Insert <method> into the queue.
    void enqueue (Method_Request *method);
    // Remove <method> into the queue.
    void dequeue (Method_Request *method);
    private:
    // ...
};