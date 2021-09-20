#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int rest = N;
	cin.get();
	set<int> stor;
	for (int i = 1; i <= N; ++i) {
		stor.insert(i);
	}
	string str;
	string ans = "";
	
	while (getline(cin, str)) {
		if (str == "HELP") {
			break;
		}
		if (stor.size() == 0) {
			ans += "NO\n";
			continue;
		}
		stringstream ss(str);
		int a;
		set<int> temp_set;
		set<int> intersect;
		while (ss >> a) {
			if (a <= N && a > 0) {
				temp_set.insert(a);
			}
		}
		set_intersection(stor.begin(), stor.end(), temp_set.begin(), temp_set.end(), inserter(intersect, intersect.begin()));
		
		if (intersect.size() * 2 > stor.size()) {
			ans += "YES\n";
			stor = intersect;
		}
		else {
			ans += "NO\n";
			for (const auto& it : intersect) {
				stor.erase(it);
			}
		}
	}
	cout << ans;
	for (const auto& it : stor) {
		cout << it << " ";
	}

	return 0;
}
