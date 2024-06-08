#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N, K;
int d[100001];
int visited[100001];
int result = 0;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int q, w;
		cin >> q >> w;
		visited[0] = 1;
		for (int j = K; j >= 1; j--)
		{
			if (j - q >= 0 and visited[j - q]) {
				d[j] = max(d[j], d[j - q] + w);
				visited[j] = 1;
			}
			if (result < d[j]) result = d[j];
		}
	}
	
	cout << result;

	return 0;
}