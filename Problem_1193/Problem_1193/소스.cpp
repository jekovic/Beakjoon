#include <iostream>

using namespace std;

int main()
{
    unsigned int X;
    cin >> X;

    /*
       1 -> 2 -> 3 -> 4 -> 5 ->
    */
    unsigned int res = 0;
    unsigned int before = 0;

    int i = 0;
    for (i = 1; ;i++)
    {
        before = res;
        res += i;
        if (res >= X)
            break;

    }
    /*
       if i is odd, mother is bigger
          ex> 1/3
       if i is even, son is bigger
          ex> 3/1
    */
    if (res == X) {
        if (i % 2 == 0)
        {
            cout << i << '/' << 1;
        }
        else {
            cout << 1 << '/' << i;
        }

    }
    else if (before + 1 == X) {

        if (i % 2 == 0) {
            cout << 1 << '/' << i;
        }
        else {//odd   
            cout << i << '/' << 1;
        }

    }
    else {
        unsigned int temp = X - (before + 1);

        if (i % 2 == 0) {
            cout << 1 + temp << '/' << i - temp;
        }
        else {//odd 
            cout << i - temp << '/' << 1 + temp;
        }

    }

    return 0;

}