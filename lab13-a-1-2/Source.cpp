#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void pressEnterToContinue();

int main() {
	string datafile;
	cout << "Enter filename: ";
	cin >> datafile;
	pressEnterToContinue();
	return 0;
}

void pressEnterToContinue() {
	char c;
	cout << "Press Enter to continue...";
	cin.ignore(1024, '\n');
	do { cin.get(c); } while (c != '\n' && c != EOF);
	return;
}