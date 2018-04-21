// lab8.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

void zadanie1() {

	fstream f;
	vector<string> vec;
	string temp;
	f.open("macbeth.txt", ios::in);
	if (f.good()) {
		while (!f.eof()) {
			f >> temp;
			temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
			transform(temp.begin(), temp.end(), temp.begin(), tolower);
			vec.push_back(temp);
		}
	}
	f.close();

	cout << "liczba wczytanych slow: " << vec.size() << endl;

}

void zadanie2() {
	fstream f;
	vector<string> vec;
	string temp;
	f.open("macbeth.txt", ios::in);
	if (f.good()) {
		while (!f.eof()) {
			f >> temp;
			temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
			transform(temp.begin(), temp.end(), temp.begin(), tolower);
			vec.push_back(temp);
		}
	}
	f.close();
	map<string, int> zlicz;
	for (int i = 0; i < vec.size(); i++) {
		zlicz[vec[i]]++;
	}

	cout << "liczba wystapien wyrazu macbeth: " << zlicz["macbeth"] << endl;
	cout << "liczba zliczonych wyrazow: " << zlicz.size() << endl;
}

void zadanie3() {
	fstream f;
	vector<string> vec;
	string temp;
	f.open("macbeth.txt", ios::in);
	if (f.good()) {
		while (!f.eof()) {
			f >> temp;
			temp.erase(std::remove_if(temp.begin(), temp.end(), ispunct), temp.end());
			transform(temp.begin(), temp.end(), temp.begin(), tolower);
			vec.push_back(temp);
		}
	}
	f.close();
	map<string, int> zlicz;
	for (int i = 0; i < vec.size(); i++) {
		zlicz[vec[i]]++;
	}

	//cout << "liczba wystapien wyrazu macbeth: " << zlicz["macbeth"] << endl;
	vector<int> _20_najpopularniejszych_wyrazow;
	for (auto it = zlicz.begin(); it != zlicz.end(); ++it) {
		_20_najpopularniejszych_wyrazow.push_back(it->second);
	}
	vector<string> _20_najpopularniejszych_wyrazow1;
	for (auto it = zlicz.begin(); it != zlicz.end(); ++it) {
		_20_najpopularniejszych_wyrazow1.push_back(it->first);
	}
	for (int i = 0; i < (_20_najpopularniejszych_wyrazow.size()) - 1; i++)
		for (int i = 0; i < (_20_najpopularniejszych_wyrazow.size())-1; i++) {
			
		if (_20_najpopularniejszych_wyrazow[i] < _20_najpopularniejszych_wyrazow[i + 1]) {
			swap(_20_najpopularniejszych_wyrazow[i], _20_najpopularniejszych_wyrazow[i + 1]);
			swap(_20_najpopularniejszych_wyrazow1[i], _20_najpopularniejszych_wyrazow1[i + 1]);

		}
	}
	for (int i = 0; i < 20; i++) {
		cout << _20_najpopularniejszych_wyrazow[i] << " " << _20_najpopularniejszych_wyrazow1[i] << endl;

	}
}

int main()
{
	int zadanie = 0;
	do {
		cout << "podaj zadanie ktore chcesz rozwiazac" << endl;
		cin >> zadanie;
		cout << endl;
		switch (zadanie) {
		case 1: zadanie1(); break;
		case 2: zadanie2();
		case 3: zadanie3();

		}
	} while (zadanie != 0);

	cout << "koniec" << endl;
	cin.ignore(1);
	return 0;
}

