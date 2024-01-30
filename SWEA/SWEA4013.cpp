#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
string gear[5]; // 기어 상태 (N극:0, S극:1)
int K; // 회전 횟수
pair<int, int> round[100]; // <회전시킬 기어 번호, 회전 방향(1:시계, -1:반시계)> 
void rotateGear(int g, int dist);
void check(int g, int dist) { // 주의할 점 : 회전하기 전에 양쪽 기어의 극이 다른지 비교해야함
    switch(g) { // 회전한 기어에 따라 연쇄적으로 기어 회전 후 확인
    case 1: // -> 2(1:2,2:6) -> 3(2:2,3:6) -> 4(3:2,4:6)
        if(gear[1].at(2) != gear[2].at(6)) {
            if(gear[2].at(2) != gear[3].at(6))  {
                if(gear[3].at(2) != gear[4].at(6)) rotateGear(4, -dist); // 4번 회전
                rotateGear(3, dist); // 3번 회전
            }
            rotateGear(2, -dist); // 2번 회전
        }     
        break;
    case 2: // -> 1(2:6,1:2) /  -> 3(2:2,3:6) -> 4(3:2,4:6)
        if(gear[2].at(6) != gear[1].at(2)) rotateGear(1, -dist);
        if(gear[2].at(2) != gear[3].at(6)) { 
            if(gear[4].at(6) != gear[3].at(2)) rotateGear(4, dist);
            rotateGear(3, -dist);
        }
        break;
    case 3: // 2(3:6,2:2) -> 1(2:6, 1:2) / 4(3:2,4:6)
        if(gear[3].at(6) != gear[2].at(2)) { 
            if(gear[2].at(6) != gear[1].at(2)) rotateGear(1, dist);
            rotateGear(2, -dist);
        }
        if(gear[3].at(2) != gear[4].at(6)) rotateGear(4, -dist);
        break;
    case 4: // 3(4:6,3:2) -> 2(3:6,2:2) -> 1(2:6,1:2)
        if(gear[4].at(6) != gear[3].at(2)) {
            if(gear[3].at(6) != gear[2].at(2)) {
                if(gear[2].at(6) != gear[1].at(2)) rotateGear(1, -dist);
                rotateGear(2, dist);
            }
            rotateGear(3, -dist);
        }
        break;
    }
    rotateGear(g, dist); 
}
void rotateGear(int g, int dist) {
    if(dist == 1) { // g번 기어를 시계방향으로 1칸 회전
        rotate(gear[g].rbegin(), gear[g].rbegin()+1, gear[g].rend());
    } else { // g번 기어를 반시계 방향으로 1칸 회전
        // cout << g<<"반시계 before: "<<gear[g]<<endl;
        rotate(gear[g].begin(), gear[g].begin()+1, gear[g].end());
        // cout << g<<"반시계 after: "<<gear[g]<<endl;
    }
}
int main(void)
{
    int tmp1, test_case, T;
    string str;
    freopen("input.txt", "r", stdin);
    cin >> T;
    for(int test_case = 1; test_case <= T; ++test_case) {
        cin >> K; // 회전 횟수
        cin.ignore(); //이전의 cin에서 받은 공백 제거
        for(int i=1; i<=4; ++i) { 
            getline(cin, str, '\n');
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            gear[i] = str;
            // cout << "str:"<<str<<endl;
        }
        for(int i=0; i<K; ++i) cin >> round[i].first >> round[i].second; // 회전할 기어, 방향
        for(int i=0; i<K; ++i) {
            //cout << round[i].first<<"번을 "<<round[i].second<<"방향으로 회전\n";
            check(round[i].first, round[i].second);
            // cout << "---round "<<i+1<<"----\n";
            // for(int j=1; j<=4; ++j) {
            //     cout << gear[j] << endl;
            // }
        }
        tmp1 = 0;
        // 톱니바퀴 점수 계산
        if(gear[1][0] == '1') tmp1 += 1;
        if(gear[2][0] == '1') tmp1 += 2;
        if(gear[3][0] == '1') tmp1 += 4;
        if(gear[4][0] == '1') tmp1 += 8;
        cout << "#" << test_case << " " << tmp1 << "\n";
    }
    return 0;
}