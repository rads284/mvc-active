#include "servant.h"

Message_Queue_Servant::Message_Queue_Servant (int size):size_(size){
}

bool Message_Queue_Servant:: empty (void) const{
	return m_q.empty();
}

bool Message_Queue_Servant:: full (void) const{
	return m_q.size()==MAX_SIZE;
}

void Message_Queue_Servant:: put (const Message x){
	m_q.push(x);
}

Message Message_Queue_Servant:: get (void){
	Message temp = m_q.front();
	m_q.pop();
	return temp;
}