#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> level;
int result = 0;
void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		level.push_back(t);
	}
}

void solve() {
	for (int i = level.size() - 2; i >= 0; i--) {
		if (level[i + 1] <= level[i]) {
			while (1) {
				level[i]--;
				result++;
				if (level[i] < level[i + 1]) break;
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