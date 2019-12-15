#ifndef ACTIVE_QUEUE_H
#define ACTIVE_QUEUE_H
#include<deque>
#include<algorithm>
#include<iostream>
#include"method_request.h"
using namespace std;
typedef deque<Method_Request*>::iterator aq_iter;

class Activation_Queue
{
    public:
    Activation_Queue();
    // ~Activation_Queue();
    // typedef ... iterator; 
    // deque <Method_Request*> get_pointer();
    // Insert <method> into the queue.
    void enqueue (Method_Request *method);
    // Remove <method> into the queue.
    void dequeue (Method_Request *method);
    aq_iter begin();
    aq_iter end();
    private:
    deque <Method_Request*> active_queue_;
    // Method_Request** arr;
};

#endif