#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, K;
vector<int>diff; vector<int>sensor;
int main(void)
{
	int tmp;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		sensor.push_back(tmp);
	}
	sort(sensor.begin(), sensor.end());
	for (int i = 1; i < N; ++i) {
		diff.push_back(sensor[i] - sensor[i - 1]);
	}
	sort(diff.begin(), diff.end(), greater<int>());
	/*for (int i = 0; i < diff.size(); ++i) {
		cout << diff[i] << " ";
	}
	cout << endl;*/
	int diffNum = diff.size();
	//cout << "diffnum:" << diffNum <<",n-1:"<<K-1 << endl;
	int res = 0;
	for (int i = K-1; i < diffNum; ++i) {
		res += diff[i];
	}
	cout << res << "\n";
	return 0;
}