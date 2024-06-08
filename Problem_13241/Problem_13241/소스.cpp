#include <iostream>

using namespace std;

long long int max(long long int a, long long int b)
{
	int k = (a > b) ? a : b;
	
	return k;
}

long long int min(long long int a, long long int b)
{
	int k = (a < b) ? a : b;

	return k;
}

long long int gcd(long long int a, long long int b)
{
	int x = max(a, b);
	int y = min(a, b);

	int ret = 1;

	while (ret > 0) {
		ret = x % y;
		x = y;
		y = ret;
	}
	return x;
}

long long int lcm(long long a, long long b)
{

	return (long long int)(a * b) / gcd(a, b);
}

int main()
{	
	int a, b;
	cin >> a >> b;

	cout << lcm(a, b);


	return 0;
}