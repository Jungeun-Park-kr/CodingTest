#pragma warning(disable:4996)
#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int main(int argc, char** argv)
{
	int test_case;
	int T = 10, t;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int tmp;
		cin >> t;
		for (int i = 0; i < 8; ++i) {
			cin >> tmp;
			//cout << tmp << "\n";
			q.push(tmp);
		}

		//for (int i = 0; i < 8; ++i) {
		//	cout << q.front() << " ";
		//}
		//cout << endl;
		bool finish = false;
		while (!finish) {
			for (int sub = 1; sub <= 5; ++sub) {
				//cout << "front:" << q.front() << ", sub:" << sub;;
				tmp = q.front() - sub;	q.pop();
				if (tmp <= 0) {
					q.push(0);  finish = true;  break;
				}
				else q.push(tmp);
				//cout << ", back:" << q.back() << endl;
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < 8; ++i) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << "\n";

	}
	return 0;
}