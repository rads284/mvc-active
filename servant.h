#include <vector>

template <typename Message>
class Message_Queue_Servant
{
    public:
    Message_Queue_Servant (size_t size);
    // Predicates.
    bool empty (void) const;
    bool full (void) const;
    // Queue operations.
    void put (const Message x);
    Message get (void);
    private:
    // Internal Queue representation.
    vector<Message> m_q;
};
// Servant.c
// implementation of the four operations
// no synchronized