#pragma warning(disable:4996)
// old style ����... (��Ž+�ù� ������ ���� Ʈ����)
#include<iostream>
#include<queue>
#include<vector>
#include <cstring>
using namespace std;
int N, M, total_house, cost[22];
vector< pair<int, int>> house;
void check(int y, int x, int k) {
	// (y,x) �κ��� k ���� �̳����� �� ������ ���ϱ� (����ź �Ÿ� : |x1-x2| + |y1-y2| < k �̸� ���� �ȿ� �ִ� ����)
	// ���� �Ⱥ���� �ִ� �� ���� �����ϱ� 

	
	
}
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int test_case, T, tmp, answer;
	freopen("input.txt", "r", stdin);
	for (int k = 1; k < 22; ++k) {
		cost[k] = (k * k + (k - 1)*(k - 1)); // ���� ����صα�
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
		for (int k = N+1; k > 0; --k) { // �ִ� K ����
			for (int i = 0; i < N; ++i) { // ��� ��ǥ�� ���� ���
				for (int j = 0; j < N; ++j) {
					cnt = 0;
					for (int h = 0; h < total_house; ++h) {
						dist = abs(i - house[h].first) + abs(j - house[h].second);
						if (dist < k) { // ���� (i,j) ���� ���� ����
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