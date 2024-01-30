#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(void)
{
    set <string> attendance;
    set <string>::iterator it;
    string s, e, q, t, name;
    int res = 0;
    cin >> s >> e >> q;
    while(true) {
        cin >> t >> name;
        if(cin.eof() == true) break;
        if (t <= s) { // 입장
            attendance.insert(name);
        }
        else if (t >= e && t <= q) { // 퇴장
            it = attendance.find(name);
            if(it != attendance.end())  {
                ++res;
                attendance.erase(it); // 퇴장 확인했으면 삭제
            }
        }
    }
    cout << res << "\n";
    return 0;
}