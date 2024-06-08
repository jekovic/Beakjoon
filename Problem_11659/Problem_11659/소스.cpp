#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;
int N, M;
vector<int> num;
int result;
int d[100001];

void dp() {
	for (int i = 1; i <= N; i++) {
		d[i] = d[i - 1] + num[i - 1];
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		num.push_back(q);
	}

	dp();

	for (int i = 0; i < M; i++) {
		int q, w;
		cin >> q >> w;
		q; w;
		
		result = d[w] - d[q - 1];
		cout << result << '\n';
	}

	return 0;
}