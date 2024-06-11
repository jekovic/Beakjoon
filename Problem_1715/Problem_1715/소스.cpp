#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int result;
bool flag = false;
void input() {
	cin >> N;

	if (N == 1) {
		flag = true;
		return;
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		pq.push(temp);
	}
}
 
void solve() {
	while (!pq.empty()) {
		int temp = pq.top();
		pq.pop();
		temp += pq.top();
		pq.pop();
		pq.push(temp);
		
		if (pq.size() == 1) {
			result += pq.top();
			return;
		}
		else {
			result += temp;
		}
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	if (flag) {
		cout << 0;
	}
	else {
		solve();

		cout << result;
	}

	return 0;
}