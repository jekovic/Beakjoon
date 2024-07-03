#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> first, second;
int result;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		first.push_back(t);
	}

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		second.push_back(t);
	}
}

void solve() {
	vector<int> temp1, temp2;
	temp1 = first;
	temp2 = second;

	sort(temp1.begin(), temp1.end());
	sort(temp2.rbegin(), temp2.rend());

	int res1 = 0;

	for (int i = 0; i < N; i++) {
		res1 += temp1[i] * temp2[i];
	}

	temp2 = first;
	temp1 = second;

	sort(temp2.begin(), temp2.end());
	sort(temp1.rbegin(), temp1.rend());

	int res2 = 0;

	for (int i = 0; i < N; i++) {
		res2 += temp1[i] * temp2[i];
	}

	result = min(res1, res2);
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << result;

	return 0;
}