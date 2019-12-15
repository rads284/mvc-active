#include "message.h"

Message::Message(string s, int i):msg_(s),i_(i){

}

void Message::display()const{
    cout << msg_ << " DISPLAY " << i_ << " \n";
}
bool Message::operator==(Message const &m) const{
    return m.msg_.compare(msg_) && m.i_==i_;
}