#include"scheduler.h"

MQ_Scheduler::MQ_Scheduler(){
    cout<<"MQ Scheduler Created\n";
    Activation_Queue *act_que_ = new Activation_Queue();
}
MQ_Scheduler::~MQ_Scheduler(){}
void MQ_Scheduler::dispatch (void)
{
    // Iterate continuously in a
    // separate thread.
    for (;;) {
        //i should be iterator of act_que_
        aq_iter i;
        for (i = act_que_->begin();i != act_que_->end ();i++) {
            // Select a Method Request ‘m’
            // whose guard evaluates to true.
            Method_Request *m = *i;
            if (m->guard ()) {
                // Remove <m> from the queue first
                // in case <call> throws an exception.
                act_que_->dequeue (m);
                m->call ();
            }
        }
    }
}
void MQ_Scheduler::enqueue (Method_Request *method) {
     cout<<"Enqueing into activation queue\n";
    //  act_que_->enqueue(method);
    // deque <Method_Request*> active_queue_;
    // active_queue_.push_back(method);
    // cout<<"Enqueued into queue: "<<active_queue_.size()<<"\n";
}