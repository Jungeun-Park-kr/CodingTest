#include <iostream>
#include <numbers>
using namespace std;
const double pi = 3.141592653589793238462643383279502;
int main(void)
{
    int r;
    cin >> r;
    cout<<fixed; // 소수점 자리수 변경한다는 뜻
    cout.precision(6); // 소수점 6자리; 해제코드: cout.unsetf(ios::fixed);
    cout << pi*r*r << "\n" << (double)r*r*2 << "\n";
    return 0;
}