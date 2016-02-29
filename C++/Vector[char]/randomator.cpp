/*
 *   Copyright (C) 2015 NikitaProAndroid
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;
int randomVal(unsigned int strLen) {
	return rand() % strLen;
}
bool isSame(vector<char> str1, vector<char> str2) {
	for (unsigned int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}
int main()
{
	unsigned long startTime = clock();

	ifstream input("input.txt");
	ofstream output("output.txt");
	vector<char> originalString;
	unsigned int length = 0, randVal1 = 0, randVal2 = 0;
	unsigned long counter = 0;
	bool first = true;

	srand((int)time(0));

	while (!input.eof()) {
		originalString.insert(originalString.end(), input.get());
	}
	input.close();
	originalString.erase(originalString.end()-1);
	vector<char> currentString = originalString;
	length = originalString.size();

	 do {
		randVal1 = randomVal(length);
		randVal2 = randomVal(length);
		char tmp = currentString[randVal1];
		currentString[randVal1] = currentString[randVal2];
		currentString[randVal2] = tmp;
		counter++;
	 } while (!isSame(originalString, currentString));
	
	if (counter > 1)
	    output << "SUCCESSFULLY FINISHED! ATTEMPS: " << counter << " TIME(ms): " << (clock() - startTime);
	else
		output << "You are lucky, selected positions for replacing symbols are the same in first attemp!";
	output.close();
    return 0;
}

