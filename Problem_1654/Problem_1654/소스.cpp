#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int K, N;
vector<long long int> have;
long long int res;

void input() {
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		long long int q;
		cin >> q;
		have.push_back(q);
	}
}

bool check(long long int n) {
	int cnt = 0;
	for (int i = 0; i != have.size(); i++) {
		cnt += (int)(have[i] / n);
	}
	if (cnt >= N) return true;
	else return false;
}

long long int bs() {
	long long int lo = 1;
	long long int hi = pow(2,31) -1;

	while (lo <= hi) {
		long long int mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid + 1;
			res = max(res, mid);
		}
		else hi = mid -1 ;
	}

	return res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	cout << bs();

	return 0;
}