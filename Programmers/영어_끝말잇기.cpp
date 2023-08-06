#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> used_words;

    char last_word = words[0][words[0].length()-1];
    used_words.push_back(words[0]);
    int i;
    for(i=1; i< words.size(); ++i) {
        if(words[i].length() == 1) { // 한 글자 단어인지 확인
            answer.push_back(((i) % n)+1); // 탈락 사람 번호
            answer.push_back((i+n) / n); // 탈락한 사람의 차례 횟수
            break;  
        }
        if(words[i][0] != last_word) { // 끝말잇기 규칙에 맞는지 확인
            answer.push_back(((i) % n)+1); // 탈락 사람 번호
            answer.push_back((i+n) / n); // 탈락한 사람의 차례 횟수
            break;    
        }
        if(find(used_words.begin(), used_words.end(), words[i]) != used_words.end()) { // 중복 단어인지 확인
            answer.push_back(((i) % n)+1);
            answer.push_back((i+n) / n);
            break;
        }
        last_word = words[i][words[i].length()-1];
        used_words.push_back(words[i]);
    }
    if(answer.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
