#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N;
double E;
vector < pair<int,int> > island;
long long set[1000001];
int getParent(int a) {
    if(set[a] == a) return a;
    return set[a] = getParent(set[a]);
}
void unionParent(int a, int b) { // 부모 병합
    a = getParent(a);
    b = getParent(b);
    if(a < b) set[b] = a; // 더 작은 값을 부모로 하기
    else set[a] = b;
}
int find(int a, int b){ // 같은 부모를 가지는지 확인
    a = getParent(a);
    b = getParent(b);
    return a == b ? true : false;
}
class Edge{
public:
    int node[2];
    long long dist;
    Edge(int a, int b) {
        this->node[0] = a;
        this->node[1] = b;
        this->dist = pow(abs(island[a].first - island[b].first),2) + (pow(abs(island[a].second-island[b].second),2));
    }
};
bool comp(Edge &e1, Edge &e2) {
    return e1.dist < e2.dist;
}
vector<Edge> adjacent;
int main(void)
{
	int test_case, T, tmp1, tmp2 = 0;
    long long res = 0;
	freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case, res = 0)
	{
        island.clear();
        adjacent.clear();
        cin >> N;
        for(int i=0; i<N; ++i) { // x 좌표만 입력
            cin >> tmp1;
            island.push_back( make_pair(tmp2, tmp1) );
            set[i]=i; // 각 섬의 부모는 각 섬 (초기값)
        }
        for(int i=0; i<N; ++i) { // y 좌표만 입력
            cin >> tmp1;
            island[i].first = tmp1;
        }
        cin >> E; // 환경 부담 세율

        // 인접 행렬 생성
        for(int i=0; i<N; ++i) {
            for(int j=0; j<N; ++j) {
                if(i!=j) {
                    adjacent.push_back(Edge(i,j));
                }
            }
        }
        
        sort(adjacent.begin(), adjacent.end(), comp); //오름차순 정렬!!!

        for(int i=0; i<adjacent.size(); ++i) { // i번째 섬에 대해서 가장 거리가 가까운 섬 j 찾기
            if(!find(adjacent[i].node[0], adjacent[i].node[1])) { // 사이클이 생기지 않으면 선택
                unionParent(adjacent[i].node[0], adjacent[i].node[1]);
                res += adjacent[i].dist;
            }
        }
        printf("#%d %lld\n", test_case, (long long)round(res*E));
	}
	return 0;
}