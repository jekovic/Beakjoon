#include <iostream>
#include <algorithm>


using namespace std;



int main()
{
	while (1)
	{
		unsigned int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		
		int arr[3] = { a,b,c };
		sort(arr, arr+3);
		
		
		string result;
		if (arr[2] >= arr[0] + arr[1])
		{
			result = "Invalid";
		}
		else {
			if (a == b && b == c)
			{
				result = "Equilateral";
			}
			else if (a == b && a != c) {
				result = "Isosceles";
			}
			else if (a == c && a != b)
			{
				result = "Isosceles";
			}
			else if (b == c && a != b)
			{
				result = "Isosceles";
			}
			else if (a != b && b != c && a != c)
			{
				result = "Scalene";
			}
		}
		

		cout << result << endl;
	}
	
	return 0;
}