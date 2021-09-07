#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, r;
    cin >> x3 >> y3 >> r;
    int x_min = min(x1, x2);
    int x_max = max(x1, x2);
    int y_min = min(x1, x2);
    int y_max = max(x1, x2);
    int recButton = max(x_min, x3 - r);
    int recTop = min(x_max, x3 + r);
    int recLeft = max(y_min, y3 - r);
    int recRight = min(y_max, y3 + r);
    for (int i = recButton; i <= recTop; ++i) {
        for (int j = )
    }

    return 0;
}
