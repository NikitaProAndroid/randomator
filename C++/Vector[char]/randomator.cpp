/*
 *   Copyright (C) 2016 NikitaProAndroid
*/

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
	if (input.fail() || input.peek() == ifstream::traits_type::eof()) {
		cerr << "input.txt does not exist or is empty!";
		exit(EXIT_FAILURE);
	}
	ofstream output("output.txt");
	vector<char> originalString;
	unsigned int length, randVal1, randVal2;
	unsigned long int counter = 0;

	srand( (int) time(NULL) );

	while (!input.eof()) {
		originalString.insert(originalString.end(), input.get());
	}
	input.close();
	originalString.erase(originalString.end()-1);

	vector<char> currentString = originalString;
	length = originalString.size();

	 do {
		randVal1 = rand() % length;
		randVal2 = rand() % length;
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
