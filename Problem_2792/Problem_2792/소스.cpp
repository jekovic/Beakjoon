#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;
int N, M;

vector<int> jewelry;

int min_jealous = 987654321;

void input() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int q;
		cin >> q;
		jewelry.push_back(q);
	}
}

void bs() {
	int lo = 1;
	int hi = 1e9;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int cnt = 0;
		for (int i = 0; i != jewelry.size(); i++) {
			if (jewelry[i] / mid > 0) {
				cnt += jewelry[i] / mid;
				if (jewelry[i] % mid != 0)
					cnt++;
			}
			else cnt++;
		}
		if (cnt <= N) {
			hi = mid - 1;
			min_jealous = min(min_jealous, mid);
		}
		else lo = mid + 1;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	cout << min_jealous;

	return 0;
}