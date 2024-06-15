#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
long long res;
long long alpha[10];
bool nonzero[10];

/*
	각 알파벳이 등장하는 자리수를 조사
	가장 높은 자리에서 등장하는 알파벳부터 9 획득
*/

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		nonzero[s[0] - 'A'] = 1; //첫 번째 자리에 있는 알파벳 0 X
		long long k = 1;
		for (int j = s.size() - 1; j >= 0; j--) {
			alpha[s[j] - 'A'] += k;
			k *= 10;
		}
	}
}

void solve() {
	bool flag = 0;
	for (int i = 0; i < 10; i++) {
		if (!alpha[i])
			flag = 1;
	}

	if (!flag) {
		//알파벳이 모두 사용되면 가장 작은 것에 0 배정
		long long min = 1e19;
		int idx;
		for (int i = 0; i < 10; i++) {
			if (!nonzero[i] and alpha[i] < min) {
				min = alpha[i];
				idx = i;
			}
		}
		alpha[idx] = 0;
	}
	sort(alpha, alpha + 10, greater<>()); // 내림차순 정렬

	for (int i = 0, j = 9; i < 10; i++, j--) {
		res += alpha[i] * j;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	solve();

	cout << res;

	return 0;
}