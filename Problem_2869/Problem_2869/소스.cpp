#include <iostream>

using namespace std;

int main()
{
    unsigned int A, B, N;
    unsigned int cnt = 0;
    cin >> A >> B >> N;
    unsigned int k = N - A;
    unsigned int n = A - B;
    int a = k % n;
    if (a < 1) {
        cnt = k / n + 1;
    }
    else {
        cnt = k / n + 2;
    }

    cout << cnt;
    /*
    unsigned int res = 0;
    unsigned int cnt = 0;
    while(1){
     res += A;
     cnt += 1;
     if(res >= N)
         break;
     res -= B;
    }
    cout << cnt;
    */
    return 0;

}