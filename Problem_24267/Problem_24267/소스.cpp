#include <iostream>

using namespace std;

long int sum_(long int k)
{
	return ((k + 1) * k) / 2;
}


int main()
{
	long int k;
	cin >> k;
	long int ret = 0;

	for (int i = 1; i <= k - 2;i++)
	{
		ret += sum_(i);
	}

	cout << ret << endl << '3';

	return 0;
}