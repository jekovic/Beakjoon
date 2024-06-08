#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int n;
int c[MAX];
int a[MAX];

void dp()
{
	for (int i = 1; i <= n; i++) {
		a[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (c[i] >  c[j]) {
				a[i] = max(a[i], a[j] + 1);
			}
		}
	}

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}

	dp();

	sort(a, a + n + 1);

	cout << a[n];

	return 0;
}