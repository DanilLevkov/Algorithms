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
	int P;
	cin >> P;
	if (P == 4) {
		cout << -1;
		return 0;
	}
	int a, b, c;
	a = P / 3;
	b = (P - a) / 2;
	c = P - a - b;
	cout << a << " " << b << " " << c << endl;

	a = 1;
	if ((P - a) % 2 == 0) {
		b = (P - a) / 2;
		c = b;
	}
	else {
		a = 2;
		b = (P - a) / 2;
		c = P - a - b;;
	}
	cout << a << " " << b << " " << c;
	return 0;
}