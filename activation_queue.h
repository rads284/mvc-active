#ifndef ACTIVE_QUEUE_H
#define ACTIVE_QUEUE_H
#include<deque>
#include"method_request.h"
using namespace std;
typedef std::deque<Method_Request>::iterator aq_iter;  
class Activation_Queue
{
    public:
    Activation_Queue();
    ~Activation_Queue();
    // typedef ... iterator;
    
    // Insert <method> into the queue.
    Activation_Queue& operator=(const Activation_Queue&) = delete;
	Activation_Queue(const Activation_Queue&) = delete;
    void enqueue (Method_Request *method);
    // Remove <method> into the queue.
    void dequeue (Method_Request *method);
    aq_iter begin();
    aq_iter end();
    private:
    deque <Method_Request> active_queue_;
};

#endif