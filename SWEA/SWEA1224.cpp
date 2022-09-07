#include <iostream>
#include <cstring>
#include <stack>
#include <cstdio>
using namespace std;
int N;
int isp(char c) { // in-stack priority
    switch (c) {
    case '(': return 0;
    case '+': case'-': return 1;
    case '*': case'/': return 2;
    }
    return -1;
}
int icp(char c) { // in-coming priority
    switch (c) {
    case '(': return 3;
    case '*': case'/': return 2;
    case '+': case'-': return 1;
    }
    return -1;
}
 
char *in_to_post(char *str) {
    int len = strlen(str);
    int idx = 0, top=0;
    char *res = (char *)malloc(sizeof(char)*(N+2));
    stack <char> st;
    for (int i = 0; i < len; ++i) {
        if ('0' <= str[i] && str[i] <= '9') { // 피연산자인 경우 => 스택에 안넣고 바로 결과 배열에 넣기
            res[idx++] = str[i];
        }
        else if (str[i] == '(') {
            st.push(str[i]); // 여는 괄호 => 무조건 push
        }
        else if (str[i] == ')') { // 닫는 괄호인 경우 => '(' 나올때 까지 다 pop해서 res에 넣기
            while (st.top() != '(') {
                res[idx++] = st.top();  st.pop();
            }
            if (st.top() == '(') st.pop();
        }
        else { // ')', '(' 제외한 연산자인 경우 : top보다 높으면 push
            if (!st.empty()) {
                top = st.top();
                if (isp(top) < icp(str[i]))  st.push(str[i]); // 들어있는 연산자보다 우선순위 높으면 바로 push
                else { // top보다 우선순위 같거나 낮은 연산자인 경우 => pop
                    while (!st.empty() && isp(top = st.top()) >= icp(str[i])) { // 우선순위 높아질 때 까지 안에있는것 pop
                        res[idx++] = top;   st.pop();
                    }
                    st.push(str[i]);
                }
            }
            else st.push(str[i]); // stack 비어있으면 바로 push
        }
 
    }
    while (!st.empty()) { // 스택에 남은거 다빼기
        res[idx++] = st.top();  st.pop(); 
    }
    res[idx] = '\0';
    return res;
}
 
int calc_post(char *str) {
    int len = strlen(str);
    int operand1, operand2, res;
    stack <int> st;
    for (int i = 0; i < len; ++i) {
        if ('0' <= str[i] && str[i] <= '9') { // 피연산자 무조건 push
            st.push(str[i]-'0');
        }
        else { // 연산자 만나는 경우 : 피연산자 2개 꺼내서 연산한 후 결과값을 다시 push
            operand2 = st.top(); st.pop();
            operand1 = st.top(); st.pop();
            switch (str[i]) {
            case '*':
                res = operand1 * operand2; break;
            case '+':
                res = operand1 + operand2; break;
            }
            st.push((int)res);
        }
    }
    return st.top();
}
 
int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    char *str;
    char *post;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d\n", &N);
        str = (char *)malloc(sizeof(char)*(N+2));
        post = (char *)malloc(sizeof(char)*(N+2));
        for (int i = 0; i < N; ++i)  str[i] = getchar();
        getchar();
        str[N] = '\0';
        post = in_to_post(str);
        int res = calc_post(post);
        printf("#%d %d\n", test_case, res); // 결과 출력
 
        free(str);  free(post);
    }
    return 0;
}