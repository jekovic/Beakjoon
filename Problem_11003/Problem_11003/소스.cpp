#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, L;
vector<int> num;

struct A {
	int val;
	int idx;
};

struct cmp {
	bool operator()(const A& a, const A& b) {
		return a.val > b.val;	
	}
};

void input() {
	cin >> N >> L;

	num.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void solve() {
	priority_queue<A, vector<A>, cmp> pq;
	
	for (int i = 0; i < N; i++) {
		A temp;
		temp.val = num[i];
		temp.idx = i;
		pq.push(temp);
		int pos = pq.top().idx;
		while (pos < i - L + 1) {
			pq.pop();
			pos = pq.top().idx;
		}
		cout << pq.top().val << ' ';
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	return 0;
}