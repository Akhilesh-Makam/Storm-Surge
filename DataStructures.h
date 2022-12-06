#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>
#include <time.h>
using namespace std;

class DataStructures {
	struct Storm {
		string name;
		int level;
		int casualties;
		string location;
		double safety;
	};

	Storm* maxHeapName[25000];
	Storm* maxHeapSafety[25000];
	Storm* maxHeapCasualties[25000];
	int maxHeapCasualtiesIndex;
	int maxHeapNameIndex;
	int maxHeapSafetyIndex;

	void insertMaxHeapName(Storm* x) {
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

	void insertMaxHeapSafety(Storm* x) {
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

	void insertMaxHeapCasualties(Storm* x) {
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

	void heapSortMaxHeapName() {
		for(int i = 24999; i > 0; i--) {
			swap(maxHeapName[0], maxHeapName[i]);
			heapifyName(i, 0);
		}
	}

	void heapSortMaxHeapSafety() {
		for (int i = 24999; i > 0; i--) {
			swap(maxHeapSafety[0], maxHeapSafety[i]);
			heapifySafety(i, 0);
		}
	}

	void heapSortMaxHeapCasualties() {
		for (int i = 24999; i > 0; i--) {
			swap(maxHeapCasualties[0], maxHeapCasualties[i]);
			heapifyCasualties(i, 0);
		}
	}

	void heapifyName(int i, int x) {
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
	void heapifySafety(int i, int x) {
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

	void heapifyCasualties(int i, int x) {
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

	void print() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm Deaths: " << maxHeapCasualties[i]->casualties << endl;
		}
	}

public:
	void loadData() {
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
		}
		heapSortMaxHeapName();
		heapSortMaxHeapSafety();
		heapSortMaxHeapCasualties();
		//print();
	}

	void printFunction1M() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << maxHeapName[i]->name << " | Level: " << maxHeapName[i]->level << " | Casualties: "
				<< maxHeapName[i]->casualties << " | Location: " << maxHeapName[i]->location
				<< " | Safety Index: " << maxHeapName[i]->safety << endl;
		}
	}

	void printFunction2M() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << maxHeapSafety[i]->name << " | Safety Index: " << maxHeapSafety[i]->safety << endl;
		}
	}

	void printFunction3M() {
		for (int i = 24999; i >= 0; i--) {
			cout << "Storm: " << maxHeapSafety[i]->name << " | Safety Index: " << maxHeapSafety[i]->safety << endl;
		}
	}

	void printFunction4M(string search) {
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

	void printFunction5M() {
		int i = 24999;
		int max = maxHeapCasualties[i]->casualties;
		while (maxHeapCasualties[i]->casualties == max) {
			cout << "Storm: " << maxHeapCasualties[i]->name << " | Location: " << maxHeapCasualties[i]->location << " | Casualties: " << maxHeapCasualties[i]->casualties << endl;
			i--;
		}
	}

	void printFunction6M() {
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
		
};
