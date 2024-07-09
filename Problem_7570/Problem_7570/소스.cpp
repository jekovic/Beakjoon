/*
	Ref) https://everenew.tistory.com/62
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

/*
	단순히 증가하는 
*/
using namespace std;

int N;
vector<int> num;
int result;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		num.push_back(t);
	}
}

int binary(vector<int> lis, int start, int end, int element) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (lis[mid] < element) start = mid + 1;
		else end = mid;
	}
	return end;
}

void solve() {
	int ret = 0;
	vector<int> lis;
	lis.push_back(num[0]);

	for (int i = 1; i < N; i++) {
		if (num[i] > lis.back()) {
			lis.push_back(num[i]);
			ret = lis.size() - 1;
		}
		int pos = binary(lis, 0, ret, num[i]);
		lis[pos] = num[i];
	}

	result = N - (ret + 1);
}

int numarr[1000001];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	/*input();

	solve();

	cout << result;*/
	cin >> N;

	int temp;
	for (int i = 0;i < N; i++) {
		cin >> temp;
		numarr[temp] = numarr[temp - 1] + 1;
		result = max(result, numarr[temp]);
	}

	cout << N - result;

	return 0;
}