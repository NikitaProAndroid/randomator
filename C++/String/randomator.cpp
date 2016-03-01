/*
 *   Copyright (C) 2016 NikitaProAndroid
*/

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

string mixString(unsigned int rand1, unsigned int rand2, string str) {
	char tmp = str[rand2];
	str[rand2] = str[rand1];
	str[rand1] = tmp;
	return str;
}
int randomVal(unsigned int strLen) {
	return rand() % strLen;
}

int main()
{
	unsigned long startTime = clock();

	ifstream input("input.txt");
	ofstream output("output.txt");
	string originalString, currentString;
	unsigned int strLength = 0;
	unsigned long counter = 0;

	srand( (int) time(0) );

	getline(input, originalString);
	input.close();

	strLength = originalString.length();
	//cout << "originalString: " << originalString << " Length: " << strLength << endl;

	currentString = mixString(randomVal(strLength), randomVal(strLength), originalString);
	if (!strcmp(originalString.c_str(), currentString.c_str())) {
		output << "You are lucky, selected positions for replacing symbols are the same in first attemp!";
		output.close();
		return 0;
	}
	counter++;

	while (strcmp(originalString.c_str(), currentString.c_str())) {
		currentString = mixString(randomVal(strLength), randomVal(strLength), currentString);
		counter++;
	}

	output << "SUCCESSFULLY FINISHED! ATTEMPS: " << counter << " SYMBOLS: " << currentString << " TIME(ms): " << (clock()-startTime);
	output.close();
}

