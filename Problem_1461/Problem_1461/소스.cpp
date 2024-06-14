#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<int> pos, neg;
int result;

void input() {
	cin >> N >> M;
	for (int i = 0;i < N; i++) {
		int t;
		cin >> t;
		if (t > 0) {
			pos.push_back(t);
		}
		else {
			neg.push_back(abs(t));
		}
	}
}

void solve() {
	int npos = pos.size();
	int nneg = neg.size();
	
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	for (int i = npos - 1; i >= 0; i -= M) {
		result += pos[i] * 2;
	}
	for (int i = nneg - 1; i >= 0; i -= M) {
		result += neg[i] * 2;
	}

	if (npos > 0 and nneg > 0) {
		if (neg[nneg - 1] > pos[npos - 1]) {
			result -= neg[nneg - 1];
		}
		else {
			result -= pos[npos - 1];
		}
	}
	else if (nneg > 0) {
		result -= neg[nneg - 1];
	}
	else {
		result -= pos[npos - 1];
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