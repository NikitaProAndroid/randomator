/*
 *   Copyright (C) 2016 NikitaProAndroid
*/

#include <ctime>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;
string mixString(unsigned int rand1, unsigned int rand2, string str) {
	char tmp = str[rand2];
	str[rand2] = str[rand1];
	str[rand1] = tmp;
	return str;
}

int main()
{
	unsigned long startTime = clock();

	ifstream input("input.txt");
	ofstream output("output.txt");
	string originalString, currentString;
	unsigned int length;
	unsigned long int counter = 0;

	srand( (int) time(NULL) );

	getline(input, originalString);
	input.close();

	length = originalString.length();

	currentString = originalString;

	do {
		currentString = mixString(rand() % length, rand() % length, currentString);
		counter++;
	} while (strncmp(originalString.c_str(), currentString.c_str(), length) != 0);

	if (counter > 1)
	    output << "SUCCESSFULLY FINISHED! ATTEMPS: " << counter << " TIME(ms): " << (clock() - startTime);
	else
		output << "You are lucky, selected positions for replacing symbols are the same in first attemp!";
	output.close();
    return 0;
}

