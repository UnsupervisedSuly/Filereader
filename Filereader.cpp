/************************************************************************
Sulaimon Yussuf
Comp 376 Programming 1

This Program will prompts the user for the name of an input file, reads
the file one character at a time, keeping a count of each alphabetic
character read, and outputs their frequencies.  

*************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int frequency[26]; // Use an array of 26 integers to keep track of the counts
	ifstream inFile; //Input file
	char ch ;

	char inFileName[26];
	string outFileName;

	//	Prompt the user for the input file
	cout << "Enter the name of the input file --> ";
	cin >> inFileName;
	cout << endl << endl;

	// Properly open the file for processing and close the file when finished
	inFile.open( inFileName );
	if (inFile.fail())
	{
		cout << "File not open" <<endl ;

		exit(1);
	}
	// initialize frequency counts to zero for each possible letter
	for (int a = 0; a < 26; a++)

	{
		frequency [a] = 0;
	}

	//Use a properly structured, eof-controlled loop to process the file
	inFile.get(ch);
	while (!inFile.eof())
	{

		ch = toupper(ch);
		
		//Check if the Character is between A and Z
		if (ch >= 'A' && ch <= 'Z')
			frequency[ch - 'A']++;
		inFile.get(ch);
	}

	// Output the total number of characters in the file, the number
	// of alphabetic and non-alphabetic characters, and the
	// frequencies of the alphabetic characters
	cout << endl << "Letter frequencies in this file are as follows." << endl;
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		cout << ch << " : " << frequency[ch - 'A'] << endl;
	}
	return 0;
}
