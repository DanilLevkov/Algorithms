#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	cin >> N;
	string in;
	in.reserve(N);
	cin >> in;
	map<char, int> m;
	for (const auto& let : in) {
		if (m.count(let) == 0) {
			m[let] = 1;
		}
		else {
			m[let]++;
		}
	}
	bool is_any_odd = false;
	char odd_ch = '9';
	for (auto& it : m) {
		int n = it.second;
		if (n % 2 == 1) {
			odd_ch = it.first;
			is_any_odd = true;
			it.second--;
			break;
		}
	}
	for (auto it = m.begin(); it != m.end(); ++it) {
		int n = it->second / 2;
		while (n > 0) {
			cout << it->first;
			--n;
		}
	}
	if (is_any_odd) {
		cout << odd_ch;
	}
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		int n = it->second / 2;
		while (n > 0) {
			cout << it->first;
			--n;
		}
	}
	return 0;
}
