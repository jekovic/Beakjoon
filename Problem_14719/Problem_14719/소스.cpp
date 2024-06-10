#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int H, W;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W;

	vector<int> water(W, 0);

	int ret = 0;

	for (int i = 0; i < W; i++) {
		cin >> water[i];
	}

	for (int i = 1; i < W - 1; i++) {
		int left = 0, right = 0;
		//left_side
		for (int j = 0; j<i; j++)
		{
			left = max(left, water[j]);
		}
		//right_side
		for (int j = i+1; j <W; j++)
		{
			right = max(right, water[j]);
		}
		
		ret += max(0, min(right, left) - water[i]);
	}

	cout << ret;

	return 0;
}