#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(void) {
    int x, y, w, h, num[4];
    cin >> x >> y >> w >> h;
    num[0] = abs(w-x);
    num[1] = x;
    num[2] = abs(h-y);
    num[3] = y;
    sort(num, &num[4]);
    cout << num[0] << "\n";
    return 0;
}