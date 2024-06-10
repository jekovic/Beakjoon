#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N;
vector<int> solution;
int ret = INT32_MAX;
int res_x, res_y;

void input() {
	cin >> N;

	solution.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
}
/*
	1. left + right > 0 -> right--

	2. left + right <= 0 -> left++
*/
void two_pointer() {
	int left = 0, right = N - 1;

	while (left < right) {
		int sum = solution[left] + solution[right];

		if (ret > abs(sum)) {
			ret = abs(sum);
			res_x = solution[left];
			res_y = solution[right];

			if (sum == 0)
				break;
		}
	
		if (sum < 0)
			left++;
		else
			right--;
	}
}


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	two_pointer();

	cout << res_x << " " << res_y;

	return 0;
}