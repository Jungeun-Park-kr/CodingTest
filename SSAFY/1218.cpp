#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
int main(void)
{
    int test_case;
	int T = 10, size;
    char tmp, top;
    bool res = true;
	freopen("input.txt", "r", stdin);
	for(test_case = 1; test_case <= T; ++test_case, res =true)
	{
        stack<char>st;
        cin >> size;
        for(int i=0; i<size; ++i) {
            cin >> tmp;
            if(tmp=='(' || tmp == '<' || tmp == '[' || tmp =='{') { // 여는 괄호는 스택에 다 넣음
                st.push(tmp);
            } else if (st.empty()) { // 닫는괄호 나왔는데 스택이 비어있으면 false
                res = false;
            } else { // 닫는괄호 나온경우: 가장 최근 여는 괄호와 짝이 맞는지 확인
                top = st.top(); st.pop(); //가장 상단 괄호 꺼내기
                switch(tmp) {
                case '}':
                    if(top != '{') res=false; 
                    break;
                case ')':
                    if(top != '(')  res=false; 
                    break;   
                case ']':
                    if(top != '[')  res=false; 
                    break;   
                case '>':
                    if(top != '<')  res=false; 
                    break;   
                }
            }
        }
        if(!st.empty()) res = false; //스택이 비어있지 않으면 짝이 맞지 않음
        cout << "#" <<test_case<<" "<< res << "\n"; //결과출력
    }
    return 0;
}