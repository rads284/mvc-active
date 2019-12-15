#include "future.h"
Message_Future::Message_Future():msg_("",0){}

Message_Future::operator Message(){
	// future<Message> put = async();
	// return fut.get();
	return msg_;
}