/*
	https://degurii.tistory.com/158
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#define MAX 1e16+1
#define ll long long

using namespace std;

ll A, B;
vector<ll> res;
int e;

void input() {
	cin >> A >> B;
}

int count_p() {
	ll temp = MAX;
	int cnt = 0;
	while (temp != 0) {
		cnt++;
		temp >>= 1;
	}
	return cnt;
}

ll count_res(ll x) {
	ll ans = x & 1;
	for (int i = e; i > 0; i--) {
		if (x & ((ll)1 << i)) {
			ans += res[i - 1] + (x - ((ll)1 << i) + 1);
			x -= (ll)1 << i;
		}
	}
	return ans;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	e = count_p();
	res.assign(e + 1, 0);
	res[0] = 1;

	for (ll i = 1; i <= e; i++) {
		res[i] = 2 * res[i-1] +((ll)1 << i);
	}

	input();
	
	cout << count_res(B) - count_res(A - 1);

	return 0;
}