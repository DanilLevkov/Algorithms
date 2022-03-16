
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum class SideType {
	begin = 0,
	end = 1
};


int main() {
	int M;
	cin >> M;
	vector<pair<int, int>> store;
	store.reserve(100000);
	int l, r;
	cin >> l >> r;
	while (l != 0 || r != 0) {
		store.push_back({ l,r });
		cin >> l >> r;
	}
	//store.push_back({ M,M });
	sort(store.begin(), store.end());
	vector<pair<int, int>> ans_vec;
	auto it = store.begin();
	int val = 0;
	while (true) {
		if (it == store.end() || it->first > val) {
			ans_vec.clear();
			break;
		}
		auto uppb = upper_bound(it, store.end(), val, [](int l, const pair<int, int>& r) {
			return l < r.first;
			});
		auto max_it = max_element(it, uppb, [](const pair<int, int>& l, const pair<int, int>& r) {
			return l.second < r.second;
			});
		ans_vec.push_back(*max_it);
		it = uppb;
		val = max_it->second;
		if (val >= M) {
			break;
		}
	}
	if (ans_vec.empty())
	{
		cout << "No solution";
	}
	else {
		cout << ans_vec.size() << '\n';
		for (auto [l, r] : ans_vec) {
			cout << l << ' ' << r << '\n';
		}
	}

	return 0;
}
