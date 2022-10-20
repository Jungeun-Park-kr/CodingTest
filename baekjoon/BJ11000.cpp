#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int N;
using namespace std;
vector < pair<int,int> > lecTime;
priority_queue<int, vector<int>, greater<int> > pq;
int main(void)
{
    int s,e;
    cin >> N;
    for(int i=0; i<N; ++i) {
        cin >> s >> e;
        lecTime.push_back(make_pair(s,e));
    }
    sort(lecTime.begin(), lecTime.end());
    
    pq.push(lecTime[0].second);
    for(int i=1; i<N; ++i) {
        pq.push(lecTime[i].second);
        if(pq.top() <= lecTime[i].first) { // 같은 곳에서 강의가능
            pq.pop(); // 같은곳에서 할 수 있으면 빼기
        }
    }
    cout << pq.size() << "\n";
    return 0;
}