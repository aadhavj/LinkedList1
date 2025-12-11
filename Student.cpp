#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

Student::Student(char* inputName, int inputAge) {
	name = new char[1000];
	strcpy(name, inputName);
	age = inputAge;
}
Student::~Student() {
	delete name;
}
char* Student::getName(){
	return name;
}
void Student::setName(char* newName){
	strcpy(name, newName);
}
int Student::getAge(){
	return age;
}
void Student::setAge(int newAge){
	age = newAge;
}
void Student::print(){
	cout << "\nName: " << name << "\nAge: " << age << endl;
}
