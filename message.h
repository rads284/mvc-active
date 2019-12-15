#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <iostream>
using namespace std;
class Message{
	public:
	Message(string s, int i);
	void display(void)const;
	bool operator==(Message const&)const;
	bool compare(string const&)const;
	private:
	string msg_;
	int i_;
};
#endif