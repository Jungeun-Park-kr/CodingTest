#include <iostream>
#include <string>
using namespace std;

char input[102]; // 배열로 했을때, string으로 했을때 속도 비교
int main(void) {
    string sen;
    int cursor = 0;
    List<vector< int > > graph(100001);
    bool flag;
    while(1) {
        cursor = 0;
        getline(cin, sen);
        if(sen == ".") break; // 종료조건
        flag = true;
        for(int i=0; i<sen.length(); i++) {
            switch(sen[i]) {
            case '[':
            case '(':
                input[cursor++] = sen[i];
                break;
            case ']':
                if( input[cursor-1] == '[') {
                    --cursor;
                } else { // 짝이 없는경우 바로 no
                    cursor = 1;
                    flag = false;
                }
                break;
            case ')':
                if( input[cursor-1] == '(') { 
                    --cursor;
                } else { // 짝이 없는경우 바로 no
                    cursor = 1;
                    flag = false;
                }
                break;
            case '.':
                break;
            }
            if(flag == false) break;
        }
        if(cursor == 0) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }

        
    }

    return 0;
}