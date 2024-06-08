#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, L;
vector<int> Rest;
int result;

void input() {
	cin >> N >> M >> L;

	Rest.assign(N + 2, 0);

	for (int i = 1; i <= N; i++) {
		cin >> Rest[i];
	}
	Rest[0] = 0;
	Rest[N + 1] = L;
	
	sort(Rest.begin(), Rest.end());
}

bool check(int mid) {
	int cnt = 0;
	
	for (int i = 1; i <= N+1; i++) {
		int gap = Rest[i] - Rest[i-1];
		cnt += gap / mid;
		if (gap % mid == 0) {
			cnt--;
		}
	}

	if (cnt <= M) return false;
	else return true;
}

void bs() {
	int lo = 1;
	int hi = L;

	//mid는 휴게소 사이 간격
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		
		if (check(mid)) {
			lo = mid + 1;
		//	result = mid;
		}
		else {
			result = mid;
			hi = mid - 1;
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