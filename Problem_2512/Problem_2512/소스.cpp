#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
vector<int> budget;
int result;

bool input() {
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		budget.push_back(q);
		sum += q;
	}
	cin >> M;
	
	sort(budget.begin(), budget.end());

	if (sum <= M)
		return true;
	else
		return false;
}

void bs() {
	int lo = 0;
	int hi = 1e9;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		int sum = 0;
		for (int i = 0; i != budget.size(); i++) {
			if (budget[i] < mid) {
				sum += budget[i];
			}
			else {
				sum += mid;
			}
		}

		if (sum > M) {
			hi = mid - 1;
		}
		else {
			result = mid;
			lo = mid + 1;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	if (input()) {
		result = budget[N - 1];
		cout << result;
	}
	else {
		bs();
		cout << result;
	}

	return 0;
}