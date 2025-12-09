#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node{
	public:
		Node();
		~Node();
		void setValue(int);
		int getValue();
		void setNext(Node*);
		Node* getNext();
	private:
		int value;
		Node* next;
};
#endif
