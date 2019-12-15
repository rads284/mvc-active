#ifndef SERVANT_H
#define SERVANT_H
#include"message.h"
#include <queue>
using namespace std;

#define MAX_SIZE 1000
class Message_Queue_Servant
{
    public:
    Message_Queue_Servant (int size);
    // Predicates.
    bool empty (void) const;
    bool full (void) const;
    // Queue operations.
    void put (const Message x);
    Message get (void);
    private:
    // Internal Queue representation.
    queue<Message> m_q;
    int size_;
};
// Servant.c
// implementation of the four operations
// no synchronized
#endif