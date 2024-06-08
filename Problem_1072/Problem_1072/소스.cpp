#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

unsigned long long X, Y;
unsigned long long Z;
long long  result;

void input() {
	cin >> X >> Y;
	Z = (unsigned long long)(Y * 100 / X);
}

void bs() {
	unsigned long long  lo = 1;
	unsigned long long  hi = X;

	while (lo <= hi) {
		long long int mid = (lo + hi) / 2;
		unsigned long long  t = (unsigned long long)((Y + mid) * 100 / (X + mid));
		if ( t <= Z) {
			lo = mid + 1;
		}
		else {
			result = mid;
			//flag = false;
			hi = mid - 1;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();
	if (result == 0) {
		result = -1;
	}
	cout << result;

	return 0;
}