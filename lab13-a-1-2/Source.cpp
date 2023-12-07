#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <iomanip>

using namespace std;

//Declaring arrays
char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
double freq[26];

bool readFromFile(string filename);
void pressEnterToContinue();

int main() {
	string datafile;
	cout << "Enter filename: ";
	cin >> datafile;
	bool status = readFromFile(datafile);
	pressEnterToContinue();
	return 0;
}

bool readFromFile(string filename) {
	ifstream inFile;
	string word;
	char letter, ch;
	int letterCount = 0, wordCount = 0;

	//ACCOUNTING FOR UNAVAILABLE FILE
	inFile.open(filename);
	if (inFile.fail()) {
		cout << "read error - sorry\n";
		return false;
	}

	//GETTING THE LETTER COUNT
	while (inFile >> word) {
		wordCount++;
		//bool isLetter = false;
		for (int i = 0; i < word.length(); ++i) {
			letter = word[i];
			if (isalpha(letter)) {
				//isLetter = true;
				for (int j = 0; j < 26; j++) {
					if (letter == alphabet[j] || letter == alphabet[j] + 32) {
						freq[j]++;
					}
				}
				letterCount++;
			}
		}
	}
	cout << "Total number of letters: " << letterCount << "\nFrequency: \n";

	
	for (int o = 0; o < 26; ++o) {
		freq[o] = (freq[o] / letterCount) * 100;
		cout << "'" << alphabet[o] << "': " << fixed << setprecision(3) << freq[o] << "\n";
	}

	inFile.close();
	return true;
}

void pressEnterToContinue() {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}