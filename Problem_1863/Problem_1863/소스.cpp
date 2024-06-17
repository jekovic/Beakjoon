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
/*
	높이가 같은 애들의 갯수만 세면 됨 
*/
vector<int> b;
int result;
stack<int> s;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		b.push_back(w);
	}
	b.push_back(0);
}

void solve() {
	for (int i = 0; i != b.size(); i++) {
		while (!s.empty() and s.top() >= b[i]) {
			if (s.top() != b[i]) result++;
			s.pop();
		}
		s.push(b[i]);
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