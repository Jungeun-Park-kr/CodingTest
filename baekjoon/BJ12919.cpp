#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool answer;
int minLen;
string S, T;
void check(string str) {
    int len = str.length();
    if (len < minLen) return; //기저조건
    if (str == S) {
        answer = true;
        return;
    }
    // 시간초과 문제로 S->T가 아니라 T->S가 되는지를 확인함
    if (str.at(len-1) == 'A') { // A를 때기
        check(str.substr(0, len-1));
    }
    if (str[0] == 'B') { // B때고 뒤집기
        str = str.substr(1, len);
        reverse(str.begin(), str.end());
        check(str);
    }
}
int main(void){
    cin >> S >> T;
    minLen = S.length();
    check(T);
    if(answer) cout << 1 << "\n";
    else cout << 0 << "\n";
    return 0;
}
