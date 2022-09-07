#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, len, max_num;
char str[11];
void dfs(int start, char tmp[11], int depth) {
    if (depth >= N) {
        //cout << atoi(tmp) << "depth:" << depth << endl;
        if (atoi(tmp) > max_num) max_num = atoi(tmp);
        return;
    }
 
    for (int i = start; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
            swap(tmp[i], tmp[j]);
            dfs(i, tmp, depth + 1);
            swap(tmp[j], tmp[i]);
        }
    }
}
int main(void)
{
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case, max_num = -1)
    {
        cin >> str >> N;
        len = strlen(str);
        if (N > len) N = len; // 길이보다 교환 횟수가 더 많으면 길이로 조정
        dfs(0, str, 0);
        cout << "#" << test_case << " " << max_num << "\n";
    }
    return 0;
}