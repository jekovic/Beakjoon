#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N, C;
vector<int> home;
int result;
vector<int> dis;

void input() {
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int q;
		cin >> q;
		home.push_back(q);
	}
	
	sort(home.begin(), home.end());

	//for (int i = 0; i < N - 1; i++) {
	//	int d = abs(home[i] - home[i + 1]);
	//	dis.push_back(d);
	//}
	
	//sort(dis.rbegin(), dis.rend());
}

void bs() {
	int lo = 1;
	int hi = 1e9;

	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		int cnt = 1;
		int temp = home[0];

		for (auto& h : home)
		{
			if (h - temp >= mid) {
				temp = h;
				cnt++;
			}
		}

		if (cnt < C) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
			result = mid;
		}
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	cout << result;

	return 0;
}