#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int P1x, P2x, P3x, P1y, P2y, P3y;

void input() {
	cin >> P1x >> P1y;
	cin >> P2x >> P2y;
	cin >> P3x >> P3y;
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	int res = ccw(P1x, P1y, P2x, P2y, P3x, P3y);

	if (res == 0) cout << 0;
	else if (res > 0) cout << 1;
	else if (res < 0) cout << -1;

	return 0;
}