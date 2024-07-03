#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> cur;
vector<int> origin;
int result;

void input() {
	cin >> N;

	cur.assign(N+1, 0);
	origin.assign(N+1, 0);

	for (int i = 0; i < N; i++) {
		cin >> cur[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> origin[i];
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		cur[i] -= origin[i];
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = 0;i < N;i++) {
			if (!cur[i]) continue;
			flag = true;
			int minv = cur[i];
			for (int j = i + 1;j <= N;j++) {
				if (cur[i] * cur[j] > 0) {
					if (abs(cur[j]) < abs(minv)) {
						minv = cur[j];
					}
				}
				else {
					result += abs(minv);
					for (int k = i;k < j;k++) cur[k] -= minv;
					i = j - 1;
					break;
				}
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << result;

	return 0;
}