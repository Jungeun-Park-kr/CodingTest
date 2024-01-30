#include <iostream>
#include <string>
using namespace std;
int main(void) {
    int tc = 0, cursor = 0;
    cin >> tc;
    string input;
    bool flag;
    while(tc--) { // tc 개수만큼 반복
        flag = true;
        cin >> input;
        cursor = 0; // 왼괄호 개수 카운트용
        if(input[0] == ')') { // 첫 번째 값이 우괄호면 바로 false
            cout << "NO\n";
        } else {
            for(int i=0; i<input.length(); i++) {
                if(input[i] == '(') { // 왼괄호 : 커서 값 증가
                    cursor++;
                } else { // ')' : 우괄호 
                    if (cursor > 0) { // 왼괄호 있는 경우
                        cursor--;
                    } else { // 왼괄호 없는 경우 false
                        flag = false;
                        break;
                    }
                }
            }
            if(flag == false || cursor != 0) cout << "NO\n";
            else cout << "YES\n";
        } 
    }
    return 0;
}