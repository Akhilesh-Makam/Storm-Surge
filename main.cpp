#include <iostream>
#include <string>
#include "DataStructures.h"
#include <time.h>
clock_t t1, t2, t3, t4;
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
	cout << "A lower safety index denotes a lower risk of casualties.\n" << endl;
	cout << "To begin, select a data strucure (type 1 for maxHeap, 2 for Unordered Map).\n" << endl; //used to alternate between data structures

	DataStructures b;
	double time = 0.00;
	t1 = clock(); //check time
	b.loadData();
	t2 = clock();
	time += (double)(t2 - t1) / CLOCKS_PER_SEC;

	int str = 0;

	while (str == 0) { //get valid input for data structure
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
		cout << "6. Find safest/most dangerous city - lowest/highest total safety index" << endl;
		cout << "7. Switch data structures" << endl;
		cout << "8. Exit SurgeSafe" << endl;
		string s = "";
		getline(cin, s);

		if (s == "1") {
			//print the storms in lexicographical order
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				b.printFunction1M();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.printAll();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "2") {
			//print the storms by ascending safety index
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				//Heap print
				b.printFunction2M();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.printSafetyLow();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "3") {
			//print the storms in descending safety index
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				//Heap print
				b.printFunction3M();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.printSafetyHigh();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "4") {
			//print the storms searched by name here
			string c;
			cout << "Enter search name (NOTE- names are case sensitive): ";
			getline(cin, c);
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				//Heap print
				b.printFunction4M(c);
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.search(c);
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "5") {
			//print the storms with highest casualty count here
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				//Heap print
				b.printFunction5M();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.printCasualtiesHigh();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "6") {
			//print the storms by descending safety index
			if (str == 1) {
				//keep track of time using time.h clock function
				t3 = clock();
				//heap print
				b.printFunction6M();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
			else if (str == 2) {
				//keep track of time using time.h clock function
				t3 = clock();
				//unordered map print
				b.printSafestCities();
				t4 = clock();
				time += (double)(t4 - t3) / CLOCKS_PER_SEC;
				cout << "Time taken: " << fixed << setprecision(4) << time << " seconds" << endl;
				cout << endl;
				time -= (double)(t4 - t3) / CLOCKS_PER_SEC;
				t4 = 0;
				t3 = 0;
			}
		}
		else if (s == "7") { //change data structure
			if (str == 1) {
				str = 2;
				cout << "Data Structure changed to Unordered Map\n" << endl;
			}
			else if (str == 2) {
				str = 1;
				cout << "Data Structure changed to MaxHeap\n" << endl;
				//unordered map print
			}
		}
		else if (s == "8") { //end SurgeSafe
			over = true;
		}
		else {//if invalid operation
			cout << "Please enter a valid operation\n" << endl;
		}
	}

	cout << "Goodbye!" << endl;


	return 0;
}