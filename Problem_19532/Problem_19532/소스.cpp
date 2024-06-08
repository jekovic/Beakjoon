#include <iostream>

using namespace std;

int main()
{

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x, y;
	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if (a * i + b * j == c)
			{
				if (d * i + e * j == f)
				{
					x = i;
					y = j;
				}
			}
		}
	}
	/*
		ax + by = c
		x = (-by+c)/a

		dx + ey = f
		x = (-ey+f)/d

		(-by+c)/a = (-ey+f)/d
		d(-by+c) = a(-ey+f)
		-bdy + dc = -aey + af
		aey-bdy = af-dc
		y(ae-bd) = af-dc
		y = (af-dc)/ae-bd
	*/
	cout << x << ' ' << y;

	return 0;
}