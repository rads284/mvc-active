#include"scheduler.h"

virtual void MQ_Scheduler::dispatch (void)
{
    // Iterate continuously in a
    // separate thread.
    for (;;) {
        //i should be iterator of act_que_
        act_que_ i;
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
     act_que_->enqueue (method);
}