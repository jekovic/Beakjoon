#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;
int n;
int a[MAX];
int grape[MAX];
vector<int> res;

bool compare(int x, int y) {
	return x < y;
}

//void dp() {
//
//	a[1] = grape[1];
//	a[2] = grape[1] + grape[2];
//	a[3] = max(grape[2] + grape[3], grape[1] + grape[3]);
//	a[4] = max(grape[1] + grape[2] + grape[4], grape[1] + grape[3] + grape[4]);
//
//	for (int i = 1; i <5; i++) {
//		res.push_back(a[i]);
//	}
//
//	for (int i = 5; i <= n; i++) {
//		a[i] = max(a[i - 2] + grape[i], a[i - 1] + grape[i]);
//		res.push_back(a[i]);
//	}
//}
//
void dp() {
	
	a[1] = grape[1];
	a[2] = grape[1] + grape[2];
	a[3] = max({ grape[2] + grape[3], grape[1] + grape[3], grape[1] + grape[2]});
	
	for (int i = 1; i < 4; i++) {
		res.push_back(a[i]);
	}

	for (int i = 4; i <= n; i++) {
		a[i] = max({ a[i - 2] + grape[i], a[i - 3] + grape[i - 1] + grape[i], a[i - 1] });
		res.push_back(a[i]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> grape[i];
	}
	
	dp();

	//sort(a, a + MAX);
	
	sort(res.begin(), res.end());

	cout << res[n-1];

	return 0;
}