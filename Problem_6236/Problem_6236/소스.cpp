#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<int> money;
int result;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		money.push_back(q);
	}
	//sort(money.begin(), money.end());
}

bool check(int mid) {
	int temp = mid;
	int day = 1;	//¿Œ√‚ »Ωºˆ 
	for (auto& m : money) {
		if (mid < m) return false;
		if (m > temp) {
			temp = mid;
			day++;
		}
		temp -= m;
	}
	return day <= M;
}

void bs() {
	int lo = 1;
	int hi = 1e9;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;	

		if (check(mid)) {
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

	bs();

	cout << result;

	return 0;
}