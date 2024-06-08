#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N, M;
vector<int> tree;

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		tree.push_back(q);
	}
	sort(tree.begin(), tree.end());
}

bool check(int k) {
	long long int c = 0;
	for (int i = 0; i != tree.size(); i++) {
		if (tree[i] > k)
			c += tree[i] - k;
	}
	if (c >= M) {
		return true;
	}
	else {
		return false;
	}
}

int bs() {
	int lo = tree[0];
	int hi = 1e10;
	int idx = -1;

	while (lo  + 1< hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	cout << bs();

	return 0;
}