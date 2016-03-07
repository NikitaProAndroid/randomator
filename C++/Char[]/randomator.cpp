/*
 *   Copyright (C) 2016 NikitaProAndroid, Quarx2
*/

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>

using namespace std;
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

	char tmp;
	char *originalStr = originalString, *currentStr = currentString;

	do {
		randVal1 = rand() % length;
		randVal2 = rand() % length;
		tmp = *(currentStr+randVal1);
		*(currentStr+randVal1) = *(currentStr+randVal2);
		*(currentStr+randVal2) = tmp;
		counter++;
	} while (strncmp(originalStr, currentStr, length) != 0);

	if (counter > 1)
		output << "SUCCESSFULLY FINISHED! ATTEMPS: " << counter << " TIME(ms): " << (clock() - startTime);
	else
		output << "You are lucky, selected positions for replacing symbols are the same in first attemp!";
	output.close();
	return 0;
}

