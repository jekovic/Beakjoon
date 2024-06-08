#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 101
/*
	연산에 대한 모든 트래킹을 수행 후 각 연산 사이에 숫자 넣어주기
*/
using namespace std;
int n;
vector<int> a;
int cnt;
int operand[4]; //0 -> add, 1 --> sub , 2 --> mul, 3 --> div
int res[12];	// 연산 방문 결과 저장 
vector<int> maxmin;
int op[12];

void findvalue() {
	int val = 0;
	for (int i = 0; i < cnt; i++) {
		if (i == 0) {
			if (op[i] == 0) // 더하기
			{
				val += a[i] + a[i + 1];
			}
			else if (op[i] == 1) // 빼기 
			{
				val += a[i] - a[i + 1];
			}
			else if (op[i] == 2) // 곱하기
			{
				val += a[i] * a[i + 1];
			}
			else if (op[i] == 3) {
				val += a[i] / a[i + 1];
			}
		}
		else {
			if (op[i] == 0) // 더하기
			{
				val += a[i + 1];
			}
			else if (op[i] == 1) // 빼기 
			{
				val -= a[i + 1];
			}
			else if (op[i] == 2) // 곱하기
			{
				val *= a[i + 1];
			}
			else if (op[i] == 3) {
				val /= a[i + 1];
			}
		}
		
	}
		maxmin.push_back(val);
}

void dfs(int x) {
	if (x == cnt) {
		for (int i = 0; i < cnt; i++) {
			//cout << res[i] << ' ';
			//op.push_back(res[i]);
			op[i] = res[i];
		}
		findvalue();
		//cout << '\n';
		return;
	}

	for (int i = 0; i < 4 ; i++) {
		if (operand[i] != 0) {
			res[x] = i;
			operand[i]--;
			dfs(x + 1);
			operand[i]++;
		}
	}

}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}

	cin >> operand[0] >> operand[1] >> operand[2] >> operand[3];
	cnt = n - 1;

	dfs(0);

	sort(maxmin.rbegin(), maxmin.rend());

	if (maxmin.size() == 1) {
		cout << maxmin.front() << '\n' << maxmin.front();
	}
	else {
		cout << maxmin.front() << '\n' << maxmin.back();
	}

	return 0;
}