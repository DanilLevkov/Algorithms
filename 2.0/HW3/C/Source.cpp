#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


int main()
{
	int N, K;
	cin >> N >> K;
	vector<bool> v;
	v.assign(N + 1, false);
	for (int k = 0; k < K; ++k) {
		int a, b;
		cin >> a >> b;
		int pos = a;
		while (pos <= N) {
			v[pos] = true;
			pos += b;
		}
	}
	int sat = 6;
	int wed = 7;
	while (sat <= N) {
		if (wed <= N) {
			v[wed] = false;
		}
		v[sat] = false;
		wed += 7;
		sat += 7;
	}
	int counter = 0;
	for (int i = 1; i <= N; ++i) {
		if (v[i]) {
			counter++;
		}
	}
	cout << counter;
	return 0;
}
