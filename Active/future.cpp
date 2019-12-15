#include "future.h"
Message_Future::Message_Future():msg_("",0){}

Message_Future::operator Message(){
	// future<Message> put = async();
	// return fut.get();
	cout << "\nMESSAGE OVERLOADING\n";
	while(msg_.compare("")!=true){
		// cout<<"Busy Wait"<<"\n";
	}		
	cout << "DONE\n";
	return msg_;

}