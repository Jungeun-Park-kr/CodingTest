#pragma warning(disable:4996)
// old style 문제... (완탐+시물 문제가 요즘 트렌드)
#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
using namespace std;
int N, M, total_house, cost[22];
vector< pair<int, int>> house;
void check(int y, int x, int k) {
	// (y,x) 로부터 k 범위 이내에서 집 개수를 구하기 (맨하탄 거리 : |x1-x2| + |y1-y2| < k 이면 범위 안에 있는 것임)
	// 손해 안볼경우 최대 집 개수 갱신하기 

	
	
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case, T, tmp, answer;
	freopen("input.txt", "r", stdin);
	for (int k = 1; k < 22; ++k) {
		cost[k] = (k * k + (k - 1)*(k - 1)); // 운영비용 계산해두기
	}
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		house.clear();
		answer = 0;
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> tmp;
				if (tmp) house.push_back({ i, j });
				
			}
		}
		int dist, cnt, total_house = house.size();
		for (int k = N+1; k > 0; --k) { // 최대 K 개수
			for (int i = 0; i < N; ++i) { // 모든 좌표에 대해 고려
				for (int j = 0; j < N; ++j) {
					cnt = 0;
					for (int h = 0; h < total_house; ++h) {
						dist = abs(i - house[h].first) + abs(j - house[h].second);
						if (dist < k) { // 집이 (i,j) 범위 내에 있음
							++cnt;
						}
					}
					int profit = M * cnt - cost[k];
					if (profit >= 0 && answer < cnt) answer = cnt;
				}
			}
		}


		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}