#include "servant.h"

Message_Queue_Servant (size_t size){
	
}

Message_Queue_Servant::bool empty (void) const{
	return m_q.empty();
}

Message_Queue_Servant::bool full (void) const{
	return m_q.size()==MAX_SIZE;
}

template<typename Message>
Message_Queue_Servant::void put (const Message x){
	m_q.push(x);
}


Message_Queue_Servant::Message get (void){
	return m_q.pop();
}