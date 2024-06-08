#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> kids;
int result;
vector<int> d;

void input() {
	cin >> N;

	kids.assign(N, 0);
	d.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> kids[i];
	}
}

void dp() {
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (kids[j] < kids[i] and d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
		result = max(result, d[i]);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	dp();

	cout <<  N - result;

	return 0;
}