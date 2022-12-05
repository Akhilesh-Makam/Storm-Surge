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

	Storm* minHeapName[25000];
	int minHeapNameIndex;

	void insertminHeapName(Storm* x) {
		minHeapName[minHeapNameIndex] = x;
		int child = minHeapNameIndex++;
		int parent = (child - 1) / 2;
		while (parent >= 0 && minHeapName[parent]->name > minHeapName[child]->name) {
			Storm* y = minHeapName[parent];
			minHeapName[parent] = minHeapName[child];
			minHeapName[child] = y;
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void sortMinHeapName() {
		for (int i = 0; i < 25000; i++) {
			cout << "Storm: " << minHeapName[i]->name << " | Level: " << minHeapName[i]->level << " | Casualties: " << minHeapName[i]->casualties << " | Location: "
				<< minHeapName[i]->location << " | Safety: " << fixed << setprecision(2) << minHeapName[i]->safety << endl;
		}
	}

public:
	void loadData() {
		minHeapNameIndex = 0;
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
			curr->safety = (curr->level * curr->casualties) / 29.9;
			//insert into Heaps and Graph here
			insertminHeapName(curr);
		}
		sortMinHeapName();
	}


		
};
