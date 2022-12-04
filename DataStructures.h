#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class DataStructures {
	struct Storm {
		string name;
		int level;
		int casualties;
		string location;
	};

	Storm* minHeapName[25000];


public:
	void loadData() {
		ifstream i;
		i.open("StormData.csv");
		string temp;
		getline(i, temp,',');
		cout << temp << endl;
		getline(i, temp, ',');
		cout << temp << endl;
		getline(i, temp, ',');
		cout << temp << endl;
		getline(i, temp, '\n');
		cout << temp << endl;
		int count = 1;
		while (getline(i, temp, ',')) {
			Storm* curr = new Storm();
			curr->name = temp;
			cout << curr->name << endl;
			getline(i, temp, ',');
			curr->level = stoi(temp);
			cout << curr->level << endl;
			getline(i, temp, ',');
			curr->casualties = stoi(temp);
			cout << curr->casualties << endl;
			getline(i, temp, '\n');
			curr->location = temp;
			cout << curr->location << endl;
			cout << "COUNT: " << count++ << endl;
			//insert into Heaps and Graph here
		}

	}
		
};
