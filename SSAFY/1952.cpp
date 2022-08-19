#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#define MAX 999999999
using namespace std;
int ticket[4], table[12], min_price;
void check(int month, int price) {
	if (month >= 12) {
		if (price < min_price)	min_price = price;
		return;
	}
	check(month + 1, price + ticket[0] * table[month]); // 1일권
	check(month + 1, price + ticket[1]); // 한달권
	check(month + 3, price + ticket[2]); // 3달권
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 4; ++i)
			cin >> ticket[i];
		for (int i = 0; i < 12; ++i)
			cin >> table[i];
		min_price = ticket[3]; // min_price 초깃값 : 1년권
		check(0, 0);
		cout << "#" <<test_case << " " << min_price << "\n";
	}
	return 0;
}