#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iomanip>
#include <stdlib.h> 
using namespace std;


int main()
{
	vector<vector<int>> v;
	v.resize(8);
	int noughts = 0;
	int crosses = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int a;
			cin >> a;
			if (a == 2) {
				noughts++;
			}
			if (a == 1) {
				crosses++;
			}
			v[i % 3].push_back(a);
			v[3 + (j % 3)].push_back(a);
			if (i == j) {
				v[6].push_back(a);
			}
			if (i + j == 2) {
				v[7].push_back(a);
			}
		}
	}
	int count = 0;
	pair<int, int> direction = { 0,0 };
	bool crosses_win = false;
	vector<int> ch1 = { 1, 1, 1 };
	vector<int> ch2 = { 2, 2, 2 };
	for (int i = 0; i < 8; ++i) {
		if (v[i] == ch1 || v[i] == ch2) {
			count++;
			if (i >= 0 && i < 3) {
				direction.first++;
			}
			if (i >= 3 && i < 6) {
				direction.second++;
			}
			if (v[i] == ch1) {
				crosses_win = true;
			}
		}
	}
	bool isOk = (direction.first <= 1) && (direction.second <= 1);

	if (abs(crosses - noughts))
		if (count >= 3) {
			cout << "NO";
			return 0;
		}

	if (count == 0) {
		if (crosses == noughts || crosses == noughts + 1) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
		return 0;
	}

	bool correct_num = false;
	if (crosses_win) {
		if (crosses == noughts + 1) {
			correct_num = true;
		}
	}
	else {
		if (crosses == noughts) {
			correct_num = true;
		}
	}

	if (count == 2) {
		if (isOk) {
			if (correct_num) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		else {
			cout << "NO";
		}
	}
	if (count == 1) {
		if (correct_num) {
			cout << "YES";
		}
		else {
			cout << "NO";
		}
	}
	return 0;
}