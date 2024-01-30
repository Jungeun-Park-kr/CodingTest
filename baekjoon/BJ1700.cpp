#include <iostream>
#include <cstring>
using namespace std;
int N, K;
int sequence[101], powerbar[101], idx[101];

int findVictim(int idx) { // 사용할 횟수 제일 적은거 뽑기, 같으면 뒤에 나오는거 뽑기
    // idx 자리부터 남은 순서 중 멀티탭에 꽂혀있는애들의 인덱스 구하기    
    // 1순위) 앞으로 쓸 일 없는애
    // 2순위) 가장 늦게 나올 애
    int victim[101];
    memset(victim, 0, sizeof(victim));
    //memcpy(victim, powerbar, sizeof(int)*N);
    int vict = -1, min_idx = -1;
    for (int i = 0; i < N; ++i) { // 멀티탭에 꽂혀있는 애들 중 가장 늦게 쓰일 애 구하기
        //int tmp = powerbar[i];
        //cout << "powerbar[i]:"<<powerbar[i]<<") ";
        for (int j = idx+1; j < K; ++j) {
            if (sequence[j] == powerbar[i]) { // 현재 멀티탭에 꽂혀있는 기기 중 남은 순서에서 몇번째인지 저장
                //cout << powerbar[i] << ": "<< j <<"번째에 나옴\n";
                victim[i] = j;
                break;
            }
        }
    }
    for(int i=0; i<N; ++i) {
        if(victim[i] == 0) { // 아예 안나오는 애부터 쫓겨나야 함
            vict = i;
            break;
        }
        else if(victim[i] > min_idx) {
            min_idx = victim[i];
            vict = i;
        }
    }
    //cout << "vict idx: " << vict <<", vict: "<< powerbar[vict] << endl;
    return vict;
}
int main(void)
{
    int swap = 0;
    cin >> N >> K; // N: 멀티탭 구멍 개수, K : 총 전기용품 사용횟수
    for (int i = 0; i < K; ++i) {
        cin >> sequence[i];
    }
    int num;
    for (int i = 0; i < K; ++i) {
        num = 0;
        for (int j = 0; j < N; ++j) {
            if (powerbar[j] == 0) { //빈자리 바로 들어가기
                powerbar[j] = sequence[i];
                num = sequence[i];
                break;
            }
            if (powerbar[j] == sequence[i]) {
                num = sequence[i];
                break;
            }
        }
        if (num == 0) { // 꽂을 자리 없는 경우
            int vic = findVictim(i);
            if (vic == -1) { // 앞으로 다 안쓰이므로 아무거나 뽑아도 됨
                powerbar[0] = sequence[i]; // 첫번째 자리로 가기
            }
            else { // 제일 늦게 사용될 애를 victime으로 뽑기
                powerbar[vic] = sequence[i];
            }
            swap++;
        }

        // cout << "멀티탭 상태) ";
        // for (int i = 0; i < N; ++i) {
        //     cout << powerbar[i] << " ";
        // }
        // cout << endl;
    }
    cout << swap << "\n";
    return 0;
}