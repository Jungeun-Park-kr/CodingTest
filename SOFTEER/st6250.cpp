#include<iostream>
#include<vector>
#include<map>

using namespace std;
int N;

int input[4][100001]; // 인풋 입력
int score_cnt[3][1001]; // 중복 점수 개수 카운트 배열
int score_rank[3][1001]; // 점수별 등수 기록 배열 (결과 출력용)
int tot_score_cnt[3001];
int tot_score_rank[3001];
map<int, int, greater<int> > desc_rank_map[4]; // 점수 내림차순 정렬 맵

int main(int argc, char** argv)
{
    int tmp, cnt;
    cin >> N;
    for(int i=0; i<3; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> tmp;
            input[i][j] = tmp;
            input[3][j] += tmp; // 최종
            score_cnt[i][tmp]++;
            desc_rank_map[i].insert({tmp, tmp});
  
        }
        int tmp_rank = 1;
        for(auto iter : desc_rank_map[i]) {
            tmp = iter.first; // 점수
            cnt = score_cnt[i][tmp]; // 점수 반복 횟수
            score_rank[i][tmp] = tmp_rank;
            tmp_rank += cnt; // 공동 등수 개수만큼 더해주기
        }
        for(int j=0; j<N-1; j++) {
            tmp = input[i][j]; // j번째 사람의 점수
            cout << score_rank[i][tmp] << " ";
        }
        tmp = input[i][N-1];
        cout <<score_rank[i][tmp] << "\n";
    }
    // 최종 점수
    for(int i=0; i<N; i++) {
        tmp = input[3][i]; // 3개 대회 점수 합산
        tot_score_cnt[tmp]++;
        desc_rank_map[3].insert({tmp, tmp});
    }
    int tmp_rank = 1;
    for(auto iter : desc_rank_map[3]) {
        tmp = iter.first; // 점수
        cnt = tot_score_cnt[tmp]; // 점수 반복 횟수
        tot_score_rank[tmp] = tmp_rank;
        tmp_rank += cnt; // 공동 등수 개수만큼 더해주기
    }
    for(int j=0; j<N-1; j++) {
        tmp = input[3][j]; // j번째 사람의 점수
        cout << tot_score_rank[tmp] <<" ";
    }
    tmp = input[3][N-1];
    cout << tot_score_rank[tmp] << "\n";
    
    return 0;
}
