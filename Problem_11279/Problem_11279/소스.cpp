#include <iostream>
#include <queue>
#include <vector>
#define MAX 100001

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//priority_queue<int, vector<int>, greater<int>> pq; //min heap
	priority_queue<int> pq;
	int n;
	cin >> n;

	for (int i = 0;i < n; i++) {
		int k;
		cin >> k;
		if (k == 0) {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else if (k > 0) {
			pq.push(k);
		}
	}

	return 0;
}