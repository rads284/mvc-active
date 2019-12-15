#include"message.h"
#include "proxy.h"
#include <thread>
#include <string>
int main(){
	Message_Queue_Proxy *mqp =  new Message_Queue_Proxy(4);
	Message *message1 = new Message("Hello1!",1);
	Message *message2 = new Message("Hello2!",2);
	Message *message3 = new Message("Hello3!",3);
	
	mqp->put(*message1);
	Message_Future result = mqp->get();
	Message message_result = (Message)result;

	mqp->put(*message2);
	Message_Future result2 = mqp->get();
	Message message_result2 = (Message)result2;


	// message_result.display();
	// while(true){}
	// mqp->~Message_Queue_Proxy();
	// thread t1(mqp.put(message));	
	// thread t2(mqp.put(message));
	// thread t3(mqp.get(message));
	// thread t4(mqp.get(message));
	// thread t5(mqp.get(message));
	// thread t6(mqp.put(message));

	// t1.join();
	// t2.join();
	// t3.join();
	// t4.join();
	// t5.join();
	// t6.join();

	// Message result = (Message)mqp->get();

	return 0;
}