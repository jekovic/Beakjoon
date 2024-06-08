#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

unsigned long long N;
unsigned long long result;

void input() {
	cin >> N;
}

void bs() {
	unsigned long long lo = 0;
	unsigned long long hi = N;

	while (lo <= hi) {
		unsigned long long mid = (lo + hi) / 2;
		if (pow(mid,2) >= N) {
			hi = mid - 1;
			result = mid;
		}
		else {
			lo = mid + 1;
		}
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();
	if (N == 0) {
		cout << 0;
		return 0;
	}

	bs();

	cout << result;

	return 0;
}