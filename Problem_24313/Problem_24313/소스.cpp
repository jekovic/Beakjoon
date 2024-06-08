#include <iostream>

using namespace std;

int main()
{

	int a1, a0;
	int c, n;

	cin >> a1 >> a0;

	cin >> c >> n;
	
	int ret = 0;

	if (a1 * n + a0 <= c * n && a1<= c)
	{

		ret = 1;
	}
	else
	{
		ret = 0;
	}

	cout << ret;

	return 0;
}