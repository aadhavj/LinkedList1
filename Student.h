#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class Student{
	public:
		Student(char*, int);
		~Student();
		char* getName();
		void setName(char*);
		int getAge();
		void setAge(int);
		void print();
	private:
		char* name;
		int age;
};
#endif
