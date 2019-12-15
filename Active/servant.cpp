#include "servant.h"

Message_Queue_Servant::Message_Queue_Servant (int size):size_(size){
	cout<<"Servant Created\n";
}

// bool Message_Queue_Servant::operator==(const Message_Queue_Servant & mqs)const{
// 	return mqs.
// }
bool Message_Queue_Servant:: empty (void) const{
	cout << m_q.empty() << " M_Q EMPTY \n";
	return m_q.empty();
}

bool Message_Queue_Servant:: full (void) const{
	return m_q.size()==MAX_SIZE;
}

void Message_Queue_Servant:: put (const Message x){
	cout<<"Put in Servant\n";
	m_q.push(x);
}

Message Message_Queue_Servant:: get (void){
	Message temp = m_q.front();
	cout<<"Get in Servant\n";
	m_q.pop();
	return temp;
}