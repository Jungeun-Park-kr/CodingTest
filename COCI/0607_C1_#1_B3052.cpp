#include <iostream>
#include <set>

using namespace std;

int main(void)
{
    int num;
    set<int> remains; // 중복 방지를 위해 set 사용

    for (int i=0; i<10; ++i) {
        cin >> num;
        remains.insert(num%42); // 42의 나머지 넣기
    }

    cout << remains.size() << "\n";

    return 0;
}