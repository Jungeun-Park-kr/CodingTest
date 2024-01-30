#include<iostream>
#include<vector>
#include <set>
#include <algorithm>

using namespace std;
set<int> s;
vector<int> vec;
int n, q, tmp;

// 1. 연비 정렬
// 2. pivot보다 작은거 개수 카운트 * pivot 뒤에 있는 개수
    // 2-1. 작은거 개수 카운트시 binary search 이용 (라이브러리 이용시 시간초과)
int binary_search(int target) {
    int left = 0, right = n-1, mid;
    while(left <= right) {
        mid = (left+right)/2;
        if(vec[mid] == target) return mid;
        else if (vec[mid] > target) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return -1; // 존재하지 않는 경우
}

int main(int argc, char** argv)
{
    cin >> n >> q;
    for(int i=0; i<n; ++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    int idx = 0;
    for(auto it: s) {
        vec.push_back(it);
    }
    for(int i=0; i<q; i++) { // 질의
        cin >> tmp;
        idx = binary_search(tmp)+1;
        //cout << "idx : "<<idx-1 << endl;
        if(idx < 1 || idx == n) // 없는숫자이거나 양 끝 숫자인 경우
            cout << "0\n";
        else cout << (idx-1)*(n-idx) << "\n";
        //idx = distance(vec.begin(), find(vec.begin(), vec.end(), tmp))+1; // 시간초과
    }
    return 0;
}
