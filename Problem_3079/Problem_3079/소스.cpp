#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N, M;
vector<unsigned long long > imigration;
unsigned long long result = 1e19;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		unsigned long long  q;
		cin >> q;
		imigration.push_back(q);
	}
}

void cal_time() {
	unsigned long long  lo = 1;
	unsigned long long  hi = 1e19;
	
	while (lo <= hi) {
		unsigned long long mid = (lo + hi) / 2;
		unsigned long long  sum = 0;
		for (int i = 0; i != imigration.size(); i++) {
			sum += (mid / imigration[i]);
		}
		if (sum >= M) {
			hi = mid - 1;
			result = min(result, mid);
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

	cal_time();

	cout << result;

	return 0;
}