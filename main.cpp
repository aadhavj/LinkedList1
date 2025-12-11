#include <iostream>
#include "node.h"
#include "Student.h"
using namespace std;

void add(Student* &newValue, Node* &head);
void printNode(Node* next, Node* head);

int main(){
	Student* a = new Student("Random 1",16);
	Student* b = new Student("Random 2", 17);
	Node* head = NULL;
	add(a,head);
	add(b,head);
	printNode(head, head);
	//add(2,head);
	//printNode(head, head);

	return 0;
}
void add(Student* &newValue, Node* &head){
	Node* current = head;
	if (current == NULL){
		head = new Node(newValue);
	}
	else{
		while (current->getNext() !=  NULL) {
			current = current->getNext();
		}
		current->setNext(new Node(newValue));
	}
}

void printNode(Node* next, Node* head){
	if (next == head) {
		cout << "list: ";
	}
	if (next != NULL) {
		next->getValue()->print();
		cout << endl;
		printNode(next->getNext(), head);
	}
	else{
		cout << endl;
	}
}
