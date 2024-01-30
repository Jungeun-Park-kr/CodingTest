#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main(void) {
    bool hasZero = false;
    string str;
    int sum = 0;
    cin >> str;
    // 30의 배수 조건 : 마지막이 0으로 끝나야 함, 각 자리수의 합이 3으로 나누어져야 함
    //
    for(char c : str) {
        if(c == '0') hasZero = true;
        sum += c-'0';
    }
    if(!hasZero || sum % 3 != 0) {
        cout << -1 << "\n";
        return 0;
    }
    sort(str.begin(), str.end(), greater<char>()); // 큰 숫자 순으로 정렬
    cout << str << "\n";
    return 0;
}