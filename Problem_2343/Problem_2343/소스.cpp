#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;
int N, M;
vector<int> Blueray;
int result;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		Blueray.push_back(q);
	}
}

bool check(int mid) {
	int sum = 0;
	int cnt = 1;
	for (auto& b : Blueray){
		if (b > mid) return true;
		sum += b;		
		if (sum > mid) {
			cnt++;
			sum = b;
			
		}
	}

	if (cnt > M) {
		return true;
	}
	else {
		return false;
	}
}

void bs() {
	int lo = 1;
	int hi = 1e9;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (check(mid)) {
			//result = mid;
			lo = mid + 1;
		}
		else {
			result = mid;
			hi = mid - 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	cout << result;

	return 0;
}