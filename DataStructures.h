#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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

	void print() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm Name: " << maxHeapSafety[i]->safety << endl;
		}
	}

public:
	void loadData() {
		maxHeapNameIndex = 0;
		maxHeapSafetyIndex = 0;
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
		}
		heapSortMaxHeapName();
		heapSortMaxHeapSafety();
		print();
	}


		
};
