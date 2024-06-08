#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

double x, y, c;
double result;

void input() {
	cin >> x >> y >> c;
}

void bs() {

	double lo = 0;
	double hi = min(x, y);

	while (hi-lo > 0.00001) {
		double mid = (lo + hi) / 2.0;
		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);
		double temp = (h1 * h2) / (h1 + h2);

		if (temp >= c) {
			lo = mid;
			result = mid;
		}
		else {
			hi = mid;
		}
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	input();

	bs();

	/*cout << fixed;
	cout.precision(3);
	cout << result;*/
	printf("%.3f", result);
	return 0;
}