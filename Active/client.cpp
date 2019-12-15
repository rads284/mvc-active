#include"message.h"
#include "proxy.h"
#include <thread>
#include <string>
int main(){
	Message_Queue_Proxy *mqp =  new Message_Queue_Proxy(4);
	Message *message1 = new Message("Hello1!",1);
	Message *message2 = new Message("Hello2!",2);
	Message *message3 = new Message("Hello3!",3);
	
	// mqp->put(*message1);
	// Message_Future result = mqp->get();
	// Message message_result = (Message)result;

	Message_Future result2 = mqp->get();
	mqp->put(*message2);
	Message message_result2 = (Message)result2;
	Message_Future result3 = mqp->get();
	mqp->put(*message2);
	mqp->put(*message3);
	Message message_result3 = (Message)result3;
	// Message message_result4 = (Message)result4;


	// mqp->put(*message1);
	// mqp->put(*message1);
	// mqp->put(*message1);
	mqp->Message_Queue_Proxy::~Message_Queue_Proxy();
	// while(true){}
	// mqp->put(*message2);
	// Message_Future result2 = mqp->get();
	// Message message_result2 = (Message)result2;
	return 0;
}