#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <climits>

using namespace std;
	
int N;
string str;
int result = INT_MIN;
	
int cal(int a, int b, char op) {
	
	int res = a;
	switch (op) {
	case '+' :
		res += b;
		break;
	case '-':
		res -= b;
		break;
	case '*':
		res *= b;
		break;
	}
	return res;
}
	
void dfs(int idx, int cur) {
	// end condition
	if (idx > N - 1) {
		result = max(result, cur);
		return;
	}
	char oper = (idx == 0) ? '+' : str[idx - 1];
	
	//°ýÈ£·Î ¹­±â
	if (idx + 2 < N) {
		int br = cal(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		dfs(idx + 4, cal(cur, br, oper));
	}
	
	//°ýÈ£·Î ¾È¹­±â --> ´ÙÀ½ + ÇöÀç 
	dfs(idx + 2, cal(cur, str[idx] - '0', oper));
}
	
int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> str;
	
	dfs(0, 0);
	
	cout << result;
	
	return 0;
}