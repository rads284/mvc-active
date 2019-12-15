#ifndef M_REQUEST_H
#define M_REQUEST_H

#include "servant.h"
#include "future.h"
class Method_Request
{
    public:
    Method_Request();
    ~Method_Request();
     bool operator==(Method_Request const&) const;
    // Evaluate the synchronization constraint.
    virtual bool guard (void) const=0;
    // Implement the method.
    virtual void call (void) =0;
};
class Put : public Method_Request
    {
        public:
        Put (Message_Queue_Servant *rep, Message arg);
        virtual bool guard (void) const;
        virtual void call (void);
        virtual bool operator==(Put const&) const;
        private:
        Message_Queue_Servant *servant_;
        Message arg_;
    };
    

class Get : public Method_Request
    {
        public:
        Get (Message_Queue_Servant *rep, Message_Future &f);
        bool guard (void) const;
        virtual void call (void) ;
        virtual bool operator==(Get const&)const;
        private:
        Message_Queue_Servant *servant_;
        // Message_Future result value.
        Message_Future &result_;
    };
#endif