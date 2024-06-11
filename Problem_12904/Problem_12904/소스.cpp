#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

string start, finish;
int result;

void input() {
	cin >> start >> finish;
}

void cal_1(string& s) {
	s.pop_back();
}

void cal_2(string& s) {
	s.pop_back();
	reverse(s.begin(), s.end());
}

void solve() {
	for (int i = finish.size() - 1; i >= 0; i--) {
		if (finish[i] == 'A') {
			cal_1(finish);
		}
		else if (finish[i] == 'B') {
			cal_2(finish);
		}

		if (finish.compare(start) == 0) {
			result = 1;
		}
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