#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <iomanip>
#include <map>
#include <time.h>
using namespace std;

class DataStructures {
	//storm pointer class that will store data
	struct Storm {
		string name;
		int level;
		int casualties;
		string location;
		double safety;
	};
	//maxHeaps used to store data that will be sorted by HeapSort
	Storm* maxHeapName[25000];
	Storm* maxHeapSafety[25000];
	Storm* maxHeapCasualties[25000];
	int maxHeapCasualtiesIndex;
	int maxHeapNameIndex;
	int maxHeapSafetyIndex;

	//creates necessary maps to store the storm's data
	unordered_map<string, vector<Storm*>> mapByStorm;
	map<string, double> mapBySafestCities;
	map<double, string> mapBySafestCities2;
	map<double, vector<string>> mapBySafetyIndex;
	map<int, vector<string>> mapByCasualties;


	//goes through the unordered map of the storms and prints all their data
	void tempPrintAll(unordered_map<string, vector<Storm*>> m1) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it.first << " | Level: " << it2->level << " | Casualties: " << it2->casualties << " | Location: " << it2->location << " | Safety Index: " << setprecision(2) << fixed << it2->safety << endl;
			}
		}
	}

	//goes through all of the storms and inserts them into the m2 which holds the safety index as its key and the vector of storm names as the key
	void printSafety(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it.first);
				}
				else {
					m2[it2->safety].push_back(it.first);
				}

			}
		}
		//it goes through m2 and prints all the data from lowest to highest
		for (auto it : m2) {
			for (auto it2 : it.second) {
				cout << "Storm: " << it2 << " | Safety Index: " << setprecision(2) << fixed << it.first << endl;
			}
		}
	}

	//does the same as above but prints all the data from highest to lowest
	void printSafety2(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it.first);
				}
				else {
					m2[it2->safety].push_back(it.first);
				}

			}
		}

		map<double, vector<string>>::reverse_iterator it2;
		for (it2 = m2.rbegin(); it2 != m2.rend(); it2++) {
			for (int i = it2->second.size() - 1; i >= 0; i--) {
				cout << "Storm: " << it2->second[i] << " | Safety Index: " << setprecision(2) << fixed << it2->first << endl;
			}
		}

	}

	//goes through the unordered map with storms and stores the safety index of each storm that happened at a specific location
	void printSafety3(unordered_map<string, vector<Storm*>> m1, map<double, vector<string>> m2, map<string, double> m3, map<double, string> m4) {
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<double, vector<string>>::iterator it3;
				it3 = m2.find(it2->safety);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->safety, v));
					m2[it2->safety].push_back(it2->location);
				}
				else {
					m2[it2->safety].push_back(it2->location);
				}

			}
		}
		//it then calculates the total safety index of every location where a storm occured and stores it in m3
		for (auto it : m2) {
			for (auto it2 : it.second) {
				map<string, double>::iterator it3;
				it3 = m3.find(it2);
				if (it3 == m3.end()) {
					m3.insert(pair<string, double>(it2, it.first));
				}
				else {
					m3[it2] += it.first;
				}
			}
		}
		//it then stores this into m4 as we are looking to sort this from lowest to highest
		for (auto it : m3) {
			m4.insert(pair<double, string>(it.second, it.first));
		}

		//it then prints out the city with the lowest safety index and then the city with the highest
		map<double, string>::iterator it2;
		it2 = m4.begin();
		cout << "The safest city is " << it2->second << " with a cumulative safety index of " << it2->first << endl;
		map<double, string>::reverse_iterator it3;
		it3 = m4.rbegin();
		cout << "The most dangerous city is " << it3->second << " with a cumulative safety index of " << it3->first << endl;
	}

	//prints all the casualties of each storm
	void printCasualties(unordered_map<string, vector<Storm*>> m1, map<int, vector<string>> m2) {
		//does the same as the print safety functions except with casualties
		for (auto it : m1) {
			for (auto it2 : it.second) {
				vector<string> v;
				map<int, vector<string>>::iterator it3;
				it3 = m2.find(it2->casualties);
				if (it3 == m2.end()) {
					m2.insert(pair<double, vector<string>>(it2->casualties, v));
					m2[it2->casualties].push_back(it.first);
				}
				else {
					m2[it2->casualties].push_back(it.first);
				}

			}
		}

		map<int, vector<string>>::reverse_iterator it2;
		for (it2 = m2.rbegin(); it2 != m2.rend(); it2++) {
			for (int i = it2->second.size() - 1; i >= 0; i--) {
				if (it2->first == 300) {
					cout << "Storm: " << it2->second[i] << " | Casualties: " << setprecision(2) << fixed << it2->first << endl;
				}
			}
		}
	}

	//is a search function and searches the name of the storm and prints all the storms with said name and their data
	void searchByName(unordered_map<string, vector<Storm*>> m1, string name) {
		unordered_map<string, vector<Storm*>>::iterator it;
		it = m1.find(name);
		if (it != m1.end()) {
			cout << "The storms with name " << name << " are:" << endl;
			for (int i = 0; i < m1[name].size(); i++) {
				cout << "Storm: " << name << " | Level: " << m1[name][i]->level << " | Casualties: " << m1[name][i]->casualties << " | Location: " << m1[name][i]->location << " | Safety Index: " << setprecision(2) << fixed << m1[name][i]->safety << endl;
			}
		}
		else {
			cout << "Sorry, no storm exists with the name " << name << "." << endl;
		}
	}

	void insertMaxHeapName(Storm* x) { //insert Storm pointer into name MaxHeap (1)
		maxHeapName[maxHeapNameIndex] = x;
		int child = maxHeapNameIndex++;
		int parent = (child - 1) / 2;
		while (parent >= 0 && maxHeapName[parent]->name < maxHeapName[child]->name) {
			Storm* y = maxHeapName[parent];
			maxHeapName[parent] = maxHeapName[child];
			maxHeapName[child] = y;
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void insertMaxHeapSafety(Storm* x) { //insert Storm pointer into safety MaxHeap (1)
		maxHeapSafety[maxHeapSafetyIndex] = x;
		int child = maxHeapSafetyIndex++;
		int parent = (child - 1) / 2;
		while (parent >= 0 && maxHeapSafety[parent]->safety < maxHeapSafety[child]->safety) {
			Storm* y = maxHeapSafety[parent];
			maxHeapSafety[parent] = maxHeapSafety[child];
			maxHeapSafety[child] = y;
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void insertMaxHeapCasualties(Storm* x) { //insert Storm pointer into casualties MaxHeap (1)
		maxHeapCasualties[maxHeapCasualtiesIndex] = x;
		int child = maxHeapCasualtiesIndex++;
		int parent = (child - 1) / 2;
		while (parent >= 0 && maxHeapCasualties[parent]->casualties < maxHeapCasualties[child]->casualties) {
			Storm* y = maxHeapCasualties[parent];
			maxHeapCasualties[parent] = maxHeapCasualties[child];
			maxHeapCasualties[child] = y;
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void heapSortMaxHeapName() { // heap sort the Name maxHeap
		for(int i = 24999; i > 0; i--) {
			swap(maxHeapName[0], maxHeapName[i]);
			heapifyName(i, 0);
		}
	}

	void heapSortMaxHeapSafety() { // heap sort the safety maxHeap
		for (int i = 24999; i > 0; i--) {
			swap(maxHeapSafety[0], maxHeapSafety[i]);
			heapifySafety(i, 0);
		}
	}

	void heapSortMaxHeapCasualties() { // heap sort the casualties maxHeap
		for (int i = 24999; i > 0; i--) {
			swap(maxHeapCasualties[0], maxHeapCasualties[i]);
			heapifyCasualties(i, 0);
		}
	}

	void heapifyName(int i, int x) { //heapify for heap sort (2)
		int lowest = x;
		int left, right;
		left = 2 * x + 1;
		right = 2 * x + 2;
		if (left < i && maxHeapName[left]->name > maxHeapName[lowest]->name)
			lowest = left;
		if (right < i && maxHeapName[right]->name > maxHeapName[lowest]->name)
			lowest = right;
		if (lowest != x) {
			swap(maxHeapName[x], maxHeapName[lowest]);
			heapifyName(i, lowest);
		}
	}
	void heapifySafety(int i, int x) { //heapify for heap sort (2)
		int lowest = x;
		int left, right;
		left = 2 * x + 1;
		right = 2 * x + 2;
		if (left < i && maxHeapSafety[left]->safety > maxHeapSafety[lowest]->safety)
			lowest = left;
		if (right < i && maxHeapSafety[right]->safety > maxHeapSafety[lowest]->safety)
			lowest = right;
		if (lowest != x) {
			swap(maxHeapSafety[x], maxHeapSafety[lowest]);
			heapifySafety(i, lowest);
		}
	}

	void heapifyCasualties(int i, int x) { //heapify for heap sort (2)
		int lowest = x;
		int left, right;
		left = 2 * x + 1;
		right = 2 * x + 2;
		if (left < i && maxHeapCasualties[left]->casualties > maxHeapCasualties[lowest]->casualties)
			lowest = left;
		if (right < i && maxHeapCasualties[right]->casualties > maxHeapCasualties[lowest]->casualties)
			lowest = right;
		if (lowest != x) {
			swap(maxHeapCasualties[x], maxHeapCasualties[lowest]);
			heapifyCasualties(i, lowest);
		}
	}

	void print() { //print function for testing purposes
		for (int i = 0; i < 25000; i++) {
			cout << "Storm Deaths: " << maxHeapCasualties[i]->casualties << endl;
		}
	}

public:
	void loadData() { //loads data from StormData.csv file, creates Storm pointer objects, and pushes them into maxHeaps and unordered set
		vector<Storm*> v;
		maxHeapNameIndex = 0;
		maxHeapSafetyIndex = 0;
		maxHeapCasualtiesIndex = 0;
		ifstream i;
		i.open("StormData.csv");
		string temp;
		getline(i, temp,',');
		getline(i, temp, ',');
		getline(i, temp, ',');
		getline(i, temp, '\n');
		int count = 1;
		while (getline(i, temp, ',')) {
			Storm* curr = new Storm();
			curr->name = temp;
			getline(i, temp, ',');
			curr->level = stoi(temp);
			getline(i, temp, ',');
			curr->casualties = stoi(temp);
			getline(i, temp, '\n');
			curr->location = temp;
			curr->safety = (curr->level * curr->casualties) / 30.0;
			//insert into Heaps and Graph here
			insertMaxHeapName(curr);
			insertMaxHeapSafety(curr);
			insertMaxHeapCasualties(curr);
			unordered_map<string, vector<Storm*>>::iterator it;
			it = mapByStorm.find(curr->name);
			if (it == mapByStorm.end()) {
				mapByStorm.insert(pair<string, vector<Storm*>>(curr->name, v));
				mapByStorm[curr->name].push_back(curr);
			}
			else {
				mapByStorm[curr->name].push_back(curr);
			}
		}
		heapSortMaxHeapName(); //calls Heap sort on all the MaxHeaps after all the insertions
		heapSortMaxHeapSafety();
		heapSortMaxHeapCasualties();
		//print();
	}

	void printFunction1M() { //prints the storms in lexicongraphical order from name MaxHeap
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << maxHeapName[i]->name << " | Level: " << maxHeapName[i]->level << " | Casualties: "
				<< maxHeapName[i]->casualties << " | Location: " << maxHeapName[i]->location
				<< " | Safety Index: " << maxHeapName[i]->safety << endl;
		}
	}

	void printFunction2M() {  //prints the storms in ascending safety order from safety MaxHeap
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << maxHeapSafety[i]->name << " | Safety Index: " << maxHeapSafety[i]->safety << endl;
		}
	}

	void printFunction3M() {  //prints the storms in descending safety order from safety MaxHeap
		for (int i = 24999; i >= 0; i--) {
			cout << "Storm: " << maxHeapSafety[i]->name << " | Safety Index: " << maxHeapSafety[i]->safety << endl;
		}
	}

	void printFunction4M(string search) { //searches the name MaxHeap for storms matching the user inputted string, prints out the storm(s) info of storms found
		vector<Storm*> result;
		for (int i = 0; i < 25000; i++) { 
			if (maxHeapName[i]->name == search) {
				result.push_back(maxHeapName[i]);
			}
		}
		if (result.size() == 0) {
			cout << "No storms found :(" << endl;
			return;
		}
		else {
			for (int i = 0; i < result.size();i++) {
				cout << "Storm: " << result[i]->name << " | Level: " << result[i]->level << " | Casualties: "
					<< result[i]->casualties << " | Location: " << result[i]->location
					<< " | Safety Index: " << result[i]->safety << endl;
			}
		}
	}

	void printFunction5M() { //prints the storms in descending casuality count from casualty MaxHeap
		int i = 24999;
		int max = maxHeapCasualties[i]->casualties;
		while (maxHeapCasualties[i]->casualties == max) {
			cout << "Storm: " << maxHeapCasualties[i]->name << " | Casualties: " << maxHeapCasualties[i]->casualties << endl;
			i--;
		}
	}

	void printFunction6M() { //finds the cumulative safety index of each location, prints out the safest and most dangerous city according to cumulative safety index
		map<string, double> count;
		for (int i = 0; i < 25000; i++) {
			count[maxHeapName[i]->location] += maxHeapName[i]->safety;
		}

		string city1 = "";
		double max = INT_MAX;
		string city2 = "";
		double min = INT_MIN;

		for (auto i = count.begin(); i != count.end();i++) {
			if (i->second < max) {
				city1 = i->first;
				max = i->second;
			}
			if (i->second > min) {
				city2 = i->first;
				min = i->second;
			}
		}
		cout << "\n";
		cout << "The safest city is " << city1 << " with a cumulative safety index of " << fixed << setprecision(3) << max << endl;
		cout << "The most dangerous city is " << city2 << " with a cumulative safety index of " << fixed << setprecision(3) << min << endl;

	}

	//prints all storms
	void printAll() {
		tempPrintAll(mapByStorm);
	}

	//prints all storms sorted by lowest to highest safety index
	void printSafetyLow() {
		printSafety(mapByStorm, mapBySafetyIndex);
	}

	//prints all storms sorted by highest to lowest safety index
	void printSafetyHigh() {
		printSafety2(mapByStorm, mapBySafetyIndex);
	}

	//prints the safest cities (the cities with the lowest safety index)
	void printSafestCities() {
		printSafety3(mapByStorm, mapBySafetyIndex, mapBySafestCities, mapBySafestCities2);
	}

	//prints the casualties of each storm from highest to low
	void printCasualtiesHigh() {
		printCasualties(mapByStorm, mapByCasualties);
	}

	//search function that searches and prints storms with a certain name
	void search(string name) {
		searchByName(mapByStorm, name);
	}
		
};
