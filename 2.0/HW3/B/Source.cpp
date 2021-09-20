#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


int main()
{
	int N, M;
	cin >> N >> M;
	set<pair<int, int>> graph;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		if (a != b) {
			graph.insert({ min(a,b), max(a,b) });
		}
	}
	cout << N << " " << graph.size() << "\n";
	for (const auto& it : graph) {
		cout << it.first << " " << it.second << "\n";
	}
	return 0;
}
