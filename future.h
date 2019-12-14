class Message_Future
{
    public:
    // ... constructors/destructors, etc.,
    // Type conversion, which blocks
    // waiting to obtain the result of the
    // asynchronous method invocation.
    operator Message();
};