#include "servant.h"
class Method_Request
{
    public:
    Method_Request();
    ~Method_Request();
    // Evaluate the synchronization constraint.
    virtual bool guard (void) const = 0;
    // Implement the method.
    virtual void call (void) = 0;
};
class Put : public Method_Request
    {
        public:
        Put (Message_Queue_Servant *rep, Message arg)
        : servant_ (rep), arg_ (arg) {}
        virtual bool guard (void) const {
            // Synchronization constraint.
            return !servant_->full ();
        }
        virtual void call (void) {
            // Enqueue message into message queue.
            servant_->put (arg_);
        }
        private:
        Message_Queue_Servant *servant_;
        Message arg_;
    };
class Get : public Method_Request
    {
        public:
        Get (Message_Queue_Servant *rep, Message_Future &f)
        : servant_ (rep), result_ (f) {}
        bool guard (void) const {
            // Synchronization constraint.
            return !servant_->empty ();
        }
        virtual void call (void) {
            // Bind the dequeued message to the
            // future result object.
            result_ = servant_->get ();
        }
        private:
        Message_Queue_Servant *servant_;
        // Message_Future result value.
        Message_Future result_;
    };