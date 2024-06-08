#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
	unsigned short a;
	cin >> a;
	int result = 0;
	if (a == 1)
	{
		result = 0;
	}
	else {
		vector<int> pos_x;
		vector<int> pos_y;
		for (int i = 0; i < a; i++) {
			int x, y;
			cin >> x >> y;

			pos_x.push_back(x);
			pos_y.push_back(y);
		}

		sort(pos_x.begin(), pos_x.end());
		sort(pos_y.begin(), pos_y.end());
		result = ((pos_x.back() - pos_x.front()) * (pos_y.back() - pos_y.front()));
	}

	cout << result;

	return 0;
}