/*
	REF
	https://kd-codebook.tistory.com/64
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

// 0 ~ 9
int matchstick[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
int N;
int num[] = { 0, 0, 1, 7, 4, 2, 0, 8, 10 };
vector<long long> small;
string big;

void make_small() {
	small.assign(101, 0);

	for (int i = 1; i < 9; i++) {
		small[i] = num[i];
	}
	small[6] = 6;

	for (int i = 9; i < 101; i++) {
		small[i] = small[i - 2] * 10 + num[2];
		for (int j = 3; j < 8; j++) {
			small[i] = min(small[i], small[i - j] * 10 + num[j]);
		}
	}
}

void make_big(int n) {
	string res = "";

	while (n) {
		if (n % 2 == 0) {
			res += "1";
			n -= 2;
		}
		else {
			res += "7";
			n -= 3;
		}
	}

	big = res;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	make_small();

	while (testcase--) {
		cin >> N;

		make_big(N);

		cout << small[N] << ' ' << big << '\n';
	}

	return 0;
}