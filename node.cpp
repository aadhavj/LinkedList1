#include "Node.h"

Node::Node() {
	value = NULL;
	next = NULL;
}
Node::~Node() {
	delete &value;
	next = NULL;
}

void Node::setValue(Student* &newValue){
	value = newValue;
}
Student* Node::getValue(){
	return value;
}
void Node::setNext(Node* newNext) {
	next = newNext;
}
Node* Node::getNext() {
	return next;
}
