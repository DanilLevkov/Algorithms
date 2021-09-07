#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iomanip>
#include <stdlib.h> 
using namespace std;

struct Dot {
	Dot(const int& a, const int& b) : x(a), y(b) {}
	int x;
	int y;
};

int dist_qrt(const Dot& a, const Dot& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main()
{
	int n;
	cin >> n;
	string ans = "";
	for (int i = 0; i < n; ++i) {
		vector<Dot> v;
		for (int j = 0; j < 4; ++j) {
			int x, y;
			cin >> x >> y;
			Dot a(x, y);
			v.push_back(a);
		}
		vector<pair<int, pair<int, int>>> distances;
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (k == j) continue;

				distances.push_back({ dist_qrt(v[j],v[k]),{j,k} });
			}
		}
		sort(distances.rbegin(), distances.rend());
		Dot d1 = v[distances[0].second.first];
		Dot d2 = v[distances[0].second.second];
		pair<int, int> center1 = { (d1.x + d2.x),(d1.y + d2.y) };
		set<int> s = { 0,1,2,3 };
		s.erase(distances[0].second.first);
		s.erase(distances[0].second.second);
		pair<int, int> center2 = { 0,0 };
		for (auto it : s) {
			center2.first += v[it].x;
			center2.second += v[it].y;
		}
		if (center1 == center2) {
			ans += "YES\n";
		}
		else {
			ans += "NO\n";
		}
	}
	cout << ans;

	return 0;
}