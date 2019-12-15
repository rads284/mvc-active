#include"scheduler.h"
#include <mutex>
MQ_Scheduler::MQ_Scheduler():act_que_(new Activation_Queue()){
    cout<<"MQ Scheduler Created \n";
}
MQ_Scheduler::~MQ_Scheduler(){
    delete act_que_;
}

void MQ_Scheduler::dispatch (void)
{
    // Iterate continuously in a
    // separate thread.
    cout<<"Starting Scheduler\n";
    mutex mtx;
    for (;;) {
        //i should be iterator of act_que_
        aq_iter i = act_que_->begin();
        while(i!=act_que_->end ()){
        // for (i = act_que_->begin();i != act_que_->end ();i++) {
            // Select a Method Request ‘m’
            // whose guard evaluates to true.
            

            Method_Request *m = *i;
            // cout << m << " M = I\n";
            if (m->guard()) {
            // mtx.lock();

                // Remove <m> from the queue first
                // in case <call> throws an exception.
                i = act_que_->dequeue (m);
                // cout << act_que_->end() - act_que_->begin() << "END ITER\n";

                // cout << i - act_que_->begin() << "INDISE ITER\n";
                m->call ();
            // mtx.unlock();
            }
            else{
                ++i;
            }
        }
    }
}
void MQ_Scheduler::enqueue (Method_Request *method) {
    //  cout<<"Enqueing into activation queue\n"<<act_que_<<"\n";
     act_que_->enqueue(method);
}

