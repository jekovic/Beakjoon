#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> tri;

	int a, b, c;
	cin >> a >> b >> c;

	tri.push_back(a);
	tri.push_back(b);
	tri.push_back(c);

	sort(tri.begin(), tri.end());

	if (tri.at(0) + tri.at(1) <= tri.at(2)) {
		tri.at(2) = tri.at(0) + tri.at(1) - 1;
	}
	int result = tri.at(0) + tri.at(1) + tri.at(2);
	cout << result;
	return 0;
}