#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string res;
	int N;
	cin >> N;
	
	int n = 0;
	while (N >= 3) {
		N -= 3;
		n++;
	}

	int m = N;

	if (n % 2 == 0) {
		if (m == 0) {
			res = "CY";
		}
		else if (m == 1) {
			res = "SK";
		}
		else if (m == 2) {
			res = "CY";
		}
	}
	else {
		if (m == 0) {
			res = "SK";
		}
		else if (m == 1) {
			res = "CY";
		}
		else if (m == 2) {
			res = "SK";
		}
	}
	
	cout << res;

	return 0;
}