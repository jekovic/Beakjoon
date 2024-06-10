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

void input() {
	cin >> N >> M;

	num.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
}

void two_pointer() {
	int left = 0, right = 0;

	int sum = num[0];
	while (right < N) {

		if (sum < M) {
			right++;
			if (right < N) {
				sum += num[right];
			}
		}
		else if (sum > M) {
			sum -= num[left];
			left++;
		}
		else if (sum == M) {
			sum -= num[left];
			left++; right++;
			if (right < N) {
				sum += num[right];
			}
			result++;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	two_pointer();

	cout << result;

	return 0;
}