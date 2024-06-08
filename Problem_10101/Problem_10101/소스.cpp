#include <iostream>

using namespace std;


int main()
{
	unsigned short tri[3] = { 0, };
	unsigned short res = 0;
	string result;
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		cin >> tri[i];
		res += tri[i];
	}

	if (res != 180)
	{
		result = "Error";
	}
	else {
		if (tri[1] == 60 && tri[2] == 60 && tri[0] == 60) {
			result = "Equilateral";
		}
		else {
			if (tri[1] != tri[2] && tri[2] != tri[0] && tri[1] != tri[0]) {
				result = "Scalene";
			}
			else {
				result = "Isosceles";
			}
		}
	}

	cout << result;

	return 0;
}