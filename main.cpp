#include <iostream>
#include "node.h"
using namespace std;

void add(int newValue, Node* &head);
void printNode(Node* next, Node* head);

int main(){
	Node* head;
	add(5,head);
	printNode(head, head);
	add(7,head);
	printNode(head, head);
	add(2,head);
	printNode(head, head);

	return 0;
}
void add(int newValue, Node* &head){
	Node* current = head;
	if (current == NULL){
		head = new Node();
		head->setValue(newValue);
	}
	else{
		while (current->getNext() !=  NULL) {
			current = current->getNext();
		}
		current->setNext(new Node());
		current->getNext()->setValue(newValue);
	}
}

void printNode(Node* next, Node* head){
	if (next == head) {
		cout << "list: ";
	}
	if (next != NULL) {
		cout << next->getValue() << " ";
		printNode(next->getNext(), head);
	}
	else{
		cout << endl;
	}
}
