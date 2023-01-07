#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
vector <pair<int, string> > words;
int main(void) {
    string str;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> str;
        words.push_back(make_pair(str.length(), str));
    }
    sort(words.begin(), words.end());
    str = "";
    for(int i=0; i<N; ++i) {
        if(str == words[i].second) continue; // 같은 단어는 skip
        else {
            cout << words[i].second <<"\n";
            str = words[i].second;
        }
    }
    return 0;
}