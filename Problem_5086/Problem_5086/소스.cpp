#include <iostream>

using namespace std;

#define factor -1
#define multiple -2
#define neither -3

int FMN(unsigned int a, unsigned int b)
{
	if (a > b && a % b == 0) {
		return multiple;
	}
	else if (a < b && b % a == 0) {
		return factor;
	}
	else {
		return neither;
	}
}

int main()
{
	while (1)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;
		else {
			if (FMN(a, b) == factor) {
				cout << "factor" << endl;
			}
			else if (FMN(a, b) == multiple) {
				cout << "multiple" << endl;
			}
			else {
				cout << "neither" << endl;
			}
		}
	}

	return 0;
}