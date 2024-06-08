#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

int N;

vector<int> building;
vector<int> res;

void see_buiiding() {
	vector<int> temp(N, 0);
	res = temp;
	for (int i = 0; i != building.size(); i++) {
		double max_lev = -9999999999;
		for (int j = i + 1; j != building.size(); j++) {
			double lev = (double)(building[j] - building[i]) / (j - i);
			if (lev > max_lev) {
				res[i]++;
				res[j]++;
				max_lev = lev;
			}
		}

	}
}

void input() {
	cin >> N;

	for (int i = 0;i < N; i++) {
		int q;
		cin >> q;
		building.push_back(q);
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	see_buiiding();

	sort(res.rbegin(), res.rend());

	cout << res[0];

	return 0;
}