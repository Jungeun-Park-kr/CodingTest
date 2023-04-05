#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, ary[21][21];
int main(void) {
	int res = 99999999;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; ++i) 
		for (int j = 1; j <= N; ++j) cin >> ary[i][j];

	vector<int> select;
	int half = N / 2;
	for (int i = 0; i < half; ++i) select.push_back(0);
	for (int i = 0; i < half; ++i) select.push_back(1);
	
	do {
		vector<int> team1;
		vector<int> team2;
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < N; ++i) {
			if (select[i]) team1.push_back(i + 1); // 1인건 team1
			else team2.push_back(i + 1); // 0인건 team2
		}
		
		for (int i = 0; i < half-1; ++i) { // 각 팀원의 시너지 값 넣기
			for (int j = i + 1; j < half; ++j) {
				//cout << "i" << i <<", team1[i]"<<team1[i]<<  ", j:" << j << ", team1[j]"<<team1[j] << ", ary[i][j]:" << ary[team1[i]][team1[j]]<< ", ary[j][i]: "<<ary[team1[j]][team1[i]] <<endl;
				sum1 += ary[team1[i]][team1[j]];
				sum1 += ary[team1[j]][team1[i]];

				sum2 += ary[team2[i]][team2[j]];
				sum2 += ary[team2[j]][team2[i]];
			}
		}
		//cout << "차이:" << abs(sum1 - sum2) << endl;
		if (res > abs(sum1 - sum2)) { // 시너지 차이 최소값 갱신
			res = abs(sum1 - sum2);
		}
	} while (next_permutation(select.begin(), select.end()));

	cout << res << "\n";
	return 0;
}