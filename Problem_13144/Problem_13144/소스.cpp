#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;
int N;
long long result;
vector<int> num;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		num.push_back(t);
	}
}

void two_point() {
	int right = 0;
	vector<bool> vis(100001, 0);

	for (int i = 0; i < N; i++) {
		while (right < N) {
			if (vis[num[right]]) break;
			vis[num[right]] = 1;
			right++;
		}
		result += right - i;
		vis[num[i]] = 0;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	two_point();

	cout << result;

	return 0;
}