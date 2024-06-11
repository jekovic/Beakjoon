//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <stack>
//#include <cmath>
//#include <cstring>
//
//using namespace std;
//const long long INF = 1e15;
//long long N;
//int result;
//vector<long long> coin;
//
//void input() {
//	cin >> N;
//}
//
//void set_arr() {
//	long long q = 1, w = 10, e = 25;
//	while (1) {
//		coin.push_back(q);
//		coin.push_back(w);
//		coin.push_back(e);
//
//		if (q > INF || w > INF || e > INF)
//			break;
//
//		q *= 100; w *= 100; e *= 100;
//	}
//}
//
//void solve() {
//
//	for (int i = 23; i >= 0; i--) {
//		result += N / coin[i];
//		N %= coin[i];
//	}
//}
//
//int main() {
//
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//
//	int testcase;
//	cin >> testcase;
//
//	set_arr();
//
//	while (testcase--) {
//
//		input();
//
//		solve();
//
//		cout << result << '\n';
//
//		result = 0;
//	}
//
//	return 0;
//}


#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

long long N;
int result;
int d[101];

void input() {
	cin >> N;
}

void dp() {
	for (int i = 1; i <= 100; i++) {
		d[i] = d[i - 1] + 1;
		if (i - 10 >= 0) d[i] = min(d[i], d[i - 10] + 1);
		if (i - 25 >= 0) d[i] = min(d[i], d[i - 25] + 1);
	}
}

void solve() {
	while (N) {
		result += d[N % 100];
		N /= 100;
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int testcase;
	cin >> testcase;

	dp();

	while (testcase--) {

		input();

		solve();

		cout << result<< '\n';

		result = 0;
	}

	return 0;
}