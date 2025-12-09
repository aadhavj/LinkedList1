#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node{
	public:
		Node();
		~Node();
		void setValue(Student*&);
		Student* getValue();
		void setNext(Node*);
		Node* getNext();
	private:
		Student* value;
		Node* next;
};
#endif
