#include <iostream>
#include <string>
#include "DataStructures.h"
using namespace std;

/*
--------SOURCES--------
(1) MODULE 5 HEAPS POWERPOINT SLIDE 38
(2) MODULE 6.1A STEPIK SOLUTIONS
*/

int main() {

	cout << "Welcome to SurgeSafe!\n" << endl;
	cout << "Press 'c' to continue...\n" << endl;
	string x = "";
	getline(cin, x);
	while (x != "c") {
		cout << "Press 'c' to continue...\n" << endl;
		getline(cin, x);
	}

	cout << "SurgeSafe is a tool designed to determine the safest \n";
	cout << "regions in the world based on a safety index that \n";
	cout << "takes into account historical casualty rates and \n";
	cout << "and location frequencies.\n" << endl;
	cout << "To begin, select a data strucure (type 1 for maxHeap, 2 for Unordered Map).\n" << endl;

	DataStructures b;
	b.loadData();
	
	int str = 0;

	while (str == 0) {
		try {
			string s = "";
			getline(cin, s);
			str = stoi(s);
		}
		catch (exception R) {
			cout << "Please enter 1 for maxHeap, 2 for Unordered Map\n" << endl;
			str = 0;
		}
		if (str > 2 || str < 0) {
			cout << "Please enter 1 for maxHeap, 2 for Unordered Map\n" << endl;
			str = 0;
		}
	}
	
	bool over = false;
	while (!over) {

		cout << "---------Storm Menu---------" << endl;
		cout << "1. Print all storms" << endl;
		cout << "2. List storms by lowest to highest safety index" << endl;
		cout << "3. List storms by highest to lowest safety index" << endl;
		cout << "4. Search storms by name" << endl;
		cout << "5. List storms with the highest casualty count" << endl;
		cout << "6. Find safest city - lowest total safety index" << endl;
		cout << "7. Switch data structures" << endl;
		cout << "8. Exit SurgeSafe" << endl;
		string s = "";
		getline(cin, s);

		if (s == "1") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "2") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "3") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "4") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "5") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "6") {
			//print the storms here
			if (str == 1) {
				//Heap print
			}
			else if (str == 2) {
				//unordered map print
			}
		}
		else if (s == "7") {
			//print the storms here
			if (str == 1) {
				str = 2;
				cout << "Data Structure changed to Unordered Map" << endl;
			}
			else if (str == 2) {
				str = 1;
				cout << "Data Structure changed to MaxHeap" << endl;
				//unordered map print
			}
		}
		else if (s == "8") {
			over = true;
		}
		else {
			cout << "Please enter a valid operation" << endl;
		}
	}

	cout << "Goodbye!" << endl;
	

	return 0;
}