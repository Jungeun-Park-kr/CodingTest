#include<iostream>
#include <cstdio>
#include <stack>
using namespace std;
char str[100];
int N, answer[100];
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %s", &N, str);
        stack<int> st;
        int tmp, top, idx = 0, size = 0;
        bool isdup = false;
        for (int i = 0; i < N; ++i, isdup = false) {
            tmp = str[i] - '0';
            while (!st.empty() && (top = st.top()) == tmp) { // 같은 숫자가 연속되는 경우
                st.pop(); // 같은 수 빼기
                isdup = true;
            }
            if (!isdup) st.push(tmp); //같은 수가 없는경우 스택에서 빼주기
        }
        size = idx = st.size();
        while (!st.empty()) { // 뒤에서부터 넣기
            answer[--idx] = st.top();
            st.pop();
        }
        answer[size] = '\0';
        printf("#%d ", test_case);
        for (int i = 0; i < size; ++i) {
            printf("%d", answer[i]);
        }
        printf("\n");
    }
    return 0;
}