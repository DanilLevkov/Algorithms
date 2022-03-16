
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> stor;
	int a;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a;
		++stor[a];
	}
	int count = 0;
	for (auto& [key, val] : stor) {
		count += val;
		val = count;
	}
	stor[-1] = 0;
	vector<int> ans(m);
	int l, r;
	for (size_t i = 0; i < m; i++)
	{
		cin >> l >> r;
		auto lb = stor.lower_bound(l);
		auto ub = stor.upper_bound(r);
		ub = prev(ub);
		lb = prev(lb);
		ans[i] = ub->second - lb->second;
	}

	for (auto x : ans) {
		cout << x << ' ';
	}

	return 0;
}
