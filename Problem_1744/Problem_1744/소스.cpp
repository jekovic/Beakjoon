#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int N;
vector<int> under, over;
long long result = 0;
int zero_cnt;
int one_cnt;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t < 0) {
			under.push_back(t);
		}
		else if (t == 0) zero_cnt++;
		else if (t == 1) one_cnt++;
		else {
			over.push_back(t);
		}
	}
}

void solve() {
	sort(under.begin(), under.end());
	sort(over.begin(), over.end());

	// 음수 계산
	for (int i = 0; i < under.size(); i += 2) {
		if (i == under.size() - 1) {
			if (zero_cnt == 0) {
				result += under[i];
			}
		}
		else result += under[i] * under[i + 1];
	}

	//양수 계산
	for (int i = over.size() - 1; i>= 0; i -= 2) {
		if (i == 0) {
			result += over[i];
		}
		else result += over[i] * over[i - 1];
	}

	result += one_cnt;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	input();
	solve();
	cout << result;
	return 0;
}