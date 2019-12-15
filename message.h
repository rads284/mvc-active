#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
using namespace std;
class Message{
	public:
	Message(string s, int i);
	private:
	string msg;
	int i;
};
#endif