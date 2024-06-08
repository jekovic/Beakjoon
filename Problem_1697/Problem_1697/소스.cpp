#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100001

using namespace std;
int n, k;
int res[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	res[start] = 0;
	if (start == k) return;

	while (!q.empty()) {
		if (q.front() == k) {
			break;
		}
		int cost = res[q.front()];
		int x = q.front() - 1;
		int y = q.front() + 1;
		int z = q.front() * 2;
		q.pop();
		if (x >= 0 && res[x] == 0) {
			res[x] = cost + 1;
			q.push(x);
		}
		if (y <= 100000 && res[y] == 0) {
			res[y] = cost + 1;
			q.push(y);
		}
		if (z <= 100000 && res[z] == 0) {
			res[z] = cost + 1;
			q.push(z);
		}
	}
}

int main() {
	cin >> n >> k;

	bfs(n);

	cout << res[k];

	return 0;
}