#include <iostream>
#include <algorithm>
using namespace std;
int maxdp[2][3], mindp[2][3];
int a, b, c;
int main(void) {
    int N;
    cin >> N;
    for(int i=0; i<3; ++i) {
        cin >> maxdp[0][i];
        mindp[0][i] = maxdp[0][i];
    }
    for(int i=1; i<N; ++i) {
        cin >> a >> b >> c;
        //  윗줄과 비교한 다음에 제일 큰/작은 값을 위로 올림 
        maxdp[1][0] = max(maxdp[0][0], maxdp[0][1]);
        maxdp[1][1] = *max_element(&maxdp[0][0], &maxdp[0][3]);
        maxdp[1][2] = max(maxdp[0][1], maxdp[0][2]);

        maxdp[0][0] = maxdp[1][0] + a;
        maxdp[0][1] = maxdp[1][1] + b;
        maxdp[0][2] = maxdp[1][2] + c;

        mindp[1][0] = min(mindp[0][0], mindp[0][1]);
        mindp[1][1] = *min_element(&mindp[0][0], &mindp[0][3]);
        mindp[1][2] = min(mindp[0][1], mindp[0][2]);

        mindp[0][0] = mindp[1][0] + a;
        mindp[0][1] = mindp[1][1] + b;
        mindp[0][2] = mindp[1][2] + c;
    }
    cout << *max_element(&maxdp[0][0], &maxdp[0][3]) << " " << *min_element(&mindp[0][0], &mindp[0][3]) << "\n";
}