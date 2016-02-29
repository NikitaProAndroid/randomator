/*
 *   Copyright (C) 2015 NikitaProAndroid, Quarx2
*/

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;
inline int randomVal(unsigned int strLen) {
	return rand() % strLen;
}
int main()
{
	unsigned long startTime = clock();

	char originalString[100];
	char currentString[100];
	FILE *input = fopen("input.txt", "r");
	ofstream output("output.txt");
	unsigned int length, randVal1, randVal2, counter = 0;

	srand( (int) time(NULL) );

	fscanf(input, "%s", originalString);
	fseek(input, 0, SEEK_SET);
	fscanf(input, "%s", currentString);
	fseek(input, 0, SEEK_END);
	length = ftell(input);

	do {
		randVal1 = randomVal(length);
		randVal2 = randomVal(length);
		char tmp = currentString[randVal1];
		currentString[randVal1] = currentString[randVal2];
		currentString[randVal2] = tmp;
		counter++;
	} while (strncmp(originalString, currentString, length) != 0);

	if (counter > 1)
		output << "SUCCESSFULLY FINISHED! ATTEMPS: " << counter << " TIME(ms): " << (clock() - startTime);
	else
		output << "You are lucky, selected positions for replacing symbols are the same in first attemp!";
	output.close();
	return 0;
}

