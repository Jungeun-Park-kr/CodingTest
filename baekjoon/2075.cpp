#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, *num, n2;
    cin >> N;
    n2 = N*N;
    num = (int *)malloc(sizeof(int)*n2);
    for(int i=0; i<n2; ++i) cin >> num[i];
    sort(num, num+n2, greater<>());
    cout << num[N-1] << "\n";
    return 0;
}