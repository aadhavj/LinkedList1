#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <ctype.h>
using namespace std;

int main(){
	//Define input string, filtered string
	char cstring[80];
	char filteredString[80];

	//Indexing filtered string
	int index = 0;

	//Get input possible palindromic string
	cout << "Enter possible palindrome here: ";
	cin.get(cstring, 80);
	cin.get();

	//Filter string
	for (int i = 0; i < strlen(cstring); i++){
		if (isalnum(cstring[i])){
			filteredString[index] = cstring[i];
			index++;
		}
	}
	filteredString[index] = '\0';

	//Reverse string copy
	char revString[80];
	for (int i = 0;i < strlen(filteredString); i++){
		revString[i] = filteredString[strlen(filteredString)-i-1];
	}
	revString[index] = '\0';
	
	
	//Lower Cases
	for (int i = 0; i< strlen(filteredString); i++)
	{
		if (not isdigit(filteredString[i])){
		filteredString[i] = tolower(filteredString[i]);}
		if (not isdigit(revString[i])){
		revString[i] = tolower(revString[i]);}
	}
	
	//Check if Palindrome
	if (strcmp(filteredString, revString) == 0){
		cout << filteredString << " is a palindrome!";
	}
	else{
		cout << filteredString << " is not a palindrome!";
	}
	return 0;
}
