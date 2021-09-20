#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;
	string in;
	in.reserve(N);
	cin >> in;
	string tmp;
	long long counter = 0;
	for (int i = 0; i < K; ++i) {
		char first;
		char second;
		cin >> tmp;
		first = tmp[0];
		second = tmp[1];

		int lefts = 0;
		for (const auto& ch : in) {
			if (ch == second) {
				counter += lefts;
			}
			if (ch == first) {
				lefts++;
			}
		}
	}
	cout << counter;
	return 0;
}
