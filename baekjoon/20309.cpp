#include <iostream>
using namespace std;

int N, tmp;
int num[300001];
int main(void)
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    bool sort = true;
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> tmp;
        if(i%2 == 1 && tmp%2 != 1) { // 홀수번째는 홀수 나와야 함
            sort = false;
        }
        if(i%2 == 0 && tmp%2 != 0) { // 짝수번째는 짝수 나와야 함
            sort = false;
        }
    }
    if (sort)   cout << "YES\n";
    else    cout << "NO\n";

    return 0;
}