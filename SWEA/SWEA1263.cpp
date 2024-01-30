#include<iostream>
#define INF 999999999
using namespace std;
int N, dist[1001][1001];
int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int test_case, T, tmp;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
        cin >> N;
        for(int i=1; i<=N; ++i) { 
            for(int j=1; j<=N; ++j) {
                cin >> tmp;
                if (i==j) dist[i][j] = 0; // 자기자신은 거리 0
                else if(tmp) dist[i][j] = 1;
                else dist[i][j] = INF;
            }
        }    
        for(int k=1; k<=N; ++k) { // 거쳐가는 노드
            for(int i=1; i<=N; ++i) { // 시작 노드
                for(int j=1; j<=N; ++j) { // 도착 노드
                    if(dist[i][k]+dist[k][j] < dist[i][j]) { // 거쳐가는것, 기존것 비교해서 작은값
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        int res = INF; //초기화
        for(int i=1; i<=N; ++i) { 
            int sum = 0;
            for(int j=1; j<=N; ++j) sum += dist[i][j];
            if(sum < res) res = sum;
        }
        cout << "#" << test_case<<" " <<res << "\n";
	}
	return 0;
}