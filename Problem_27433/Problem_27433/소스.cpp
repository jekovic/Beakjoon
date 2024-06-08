#include <iostream>

using namespace std;

unsigned long fact(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

int main()
{
	int k = 0;
	cin >> k;
	
	cout << fact(k) << endl;

	return 0;
}