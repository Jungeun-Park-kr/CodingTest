#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


int N, M, K, dx[4] = {1,0,-1,0}, dy[4]={0,1,0,-1}, dx2[8] = {-1, 0, 1, -1, 1, -1, 0, 1}, dy2[8]={1, 1, 1, 0, 0, -1, -1, -1};
int turret[11][11];
int atime[11][11]; // 공격 시점
bool visited[11][11];
vector<pair<int, int> > track; // 경로 추적
vector<pair <int, int> > survive; // 살아있는 포탑

struct mincmp { // 공격자 선정, 공격력 오름차, 공격 최신순(내림차) , <행, 열 내림차>합 큰순서 > 
    bool operator() (const pair<int, int> &t1, const pair<int, int> &t2) {
        if(turret[t1.first][t1.second] == turret[t2.first][t2.second]) { // 공격력 같은경우
            if(atime[t1.first][t1.second] == atime[t2.first][t2.second]) { // 공격 시점 같은 경우
                if(t1.first+t1.second == t2.first+t2.second) { // 행+열 합 같은 경우
                    return t1.second > t2.second; // 열 내림차
                } else { // 열+행 합 내림차
                    return atime[t1.first][t1.second] > atime[t2.first][t2.second];
                }
            } else {
                return t1.first < t2.first; //  공격시점 내림차 (최신순)
            }
        } else { 
            return turret[t1.first][t1.second] > turret[t2.first][t2.second]; // 공격력 오름차
        }
    }
};
struct maxcmp { // 피공격자 선정, 공격력 내림차, 공격 오래된순(오름차) , <행, 열 오름차>합 작은순서 > 
    bool operator() (const pair<int, int> &t1, const pair<int, int> &t2) {
        if(turret[t1.first][t1.second] == turret[t2.first][t2.second]) { // 공격력 같은경우
            if(atime[t1.first][t1.second] == atime[t2.first][t2.second]) { // 공격 시점 같은 경우
                if(t1.first+t1.second == t2.first+t2.second) {
                    return t1.second < t2.second; // 열 오름차
                } else { // 열+행 합 오름차
                    return atime[t1.first][t1.second] < atime[t2.first][t2.second];
                }
            } else {
                return t1.first > t2.first; //  공격시점 오름차 (오래된 순)
            }
        } else { 
            return turret[t1.first][t1.second] < turret[t2.first][t2.second];// 공격력 내림차
        }
    }
};
priority_queue <pair<int, int>, vector<pair<int, int> >, maxcmp> maxpq;
priority_queue <pair<int, int>, vector<pair<int, int> >, mincmp> minpq;
// 레이저 쏠 수 있는지 확인
bool checkLaser(int attY, int attX, int pattY, int pattX) {
    memset(visited, false, sizeof(visited));
    track = vector<pair<int, int> >();
    queue<pair<int, int> > q;
    q.push(make_pair(attY, attX));
    visited[attY][attX] = true;
    int newY, newX, curY, curX;
    bool flag = false;
    while(!q.empty()) {
        
        curY = q.front().first;
        curX = q.front().second;
        q.pop();
        cout << "### "<<curY<<","<<curX<<endl;
        for(int i=0; i<4; i++) {
            newY = curY+dy[i]; 
            newX = curX+dx[i];
            cout << "newY:"<<newY<<", newX:"<<newX <<endl;
            if(newY < 0 || newY >= N || newX < 0 || newX >= M ) { // 반대편 범위 체크
                if(newY >= N) newY = newY % N; // 모서리 처리
                    else if(newY < 0) newY += N;
                    if(newX >= M) newX = newX % N;
                    else if (newX < 0) newX += M;
                cout <<" 변경 후 " << "newY:"<<newY<<", newX:"<<newX<< ", => "<< turret[newY][newX]<<endl;
            }   
            if(visited[newY][newX] || turret[newY][newX] <= 0) continue; // 범위 유효성 체크
            if(newY == pattY && newX == pattX) return true;
            visited[newY][newX] = true;
            q.push(make_pair(newY, newX));
            track.push_back(make_pair(newY, newX));
            break;
        }
    }
    return false;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // turret 초기화
    cin >> N >> M >> K;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> turret[i][j];
            if(turret[i][j] > 0) {
                minpq.push(make_pair(i, j));
                maxpq.push(make_pair(i, j));
                survive.push_back(make_pair(i, j));
            }
        }
    }
    for(int k=1; k<=K; k++) { // K 까지 턴 돌기
        // 1. 공격자 선정
        int attY = minpq.top().first; // 공격자 y축
        int attX = minpq.top().second; // 공격자 x축
        int attTurn = atime[attY][attX]; // 공격 시점
        int att =  turret[attY][attX]; // 공격력
        int attImp = att+N+M; // 향상된 공격력
        int hatt = attImp/2; // 절반 공격력
        cout << "공격자 :"<< attY<<","<<attX<< endl;
        cout << "원래 공격력:" <<att << ", 향상된 공격력:"<<attImp<<endl;
        minpq.pop();

        // 2. 피공격자 선정
        cout <<"max pq size :"<<maxpq.size()<<endl;
        int pattY = maxpq.top().first; // 피공격자 y축
        int pattX = maxpq.top().second; // 피공격자 x축
        int patt = turret[pattY][pattX]; // 피공격력
        int pattTurn = atime[pattY][pattX]; // 피공격자 공격 시점
        cout << "피공격자 :"<<pattY<<", "<<pattX<<endl;

        maxpq.pop();


        int y, x;
        turret[attY][attX] = attImp;
        atime[attY][attX] = k; // 공격 시점 갱신

        // 3. 레이저 공격 확인
        
        if(checkLaser(attY, attX, pattY, pattX)) { //  레이저 가능 ) 3-1. 레이저 공격
            cout << "######## laser "<<endl;
            turret[pattY][pattX] -= attImp;
            if(turret[pattY][pattX] < 0) turret[pattY][pattX] = 0;
            for(int i=0; i<track.size(); i++) { // 경로에 있는 포탑 공격력 빼기
                y = track[i].first;
                x = track[i].second;
                turret[y][x] -= hatt;
                if(turret[y][x] < 0) turret[y][x] = 0;
            }
        } else { //  레이저 불가 ) 3-2. 폭탄 공격
            cout << "######## bomb "<<endl;
            track = vector<pair<int, int> >();
            turret[pattY][pattX] -= attImp;
            if(turret[pattY][pattX] < 0) turret[pattY][pattX] = 0;
            // if(attY > 0 && attY < (N-1) && attX > 0 && attX < (M-1)) { // 모서리 아닌 경우 => 주변 8칸 다맞기
            for(int i=0; i<8; i++) { // 공격 주변 8칸 맞기
                int y = pattY+dy2[i]; 
                int x = pattX+dx2[i];
                if(y >= N) y = (y -1) % N; // 모서리 처리
                else if(y < 0) y += N;
                if(x >= M) x = (x-1) % N;
                else if (x < 0) x += M;

                turret[y][x] -= hatt; // 반만큼 공격력 까기
                if(turret[y][x] < 0) turret[y][x] = 0;
                track.push_back(make_pair(y, x)); // 공격받은 포탑 저장
            }
        // }
        }
        
        cout <<" \n공격경로 : ";
        for(int i=0; i<track.size(); i++) {
            cout <<"(" << track[i].first <<","<<track[i].second<<") - ";
        }
        cout << endl;
    
        // pq 갱신
        // 공격력 0 미만인것 제외
        minpq = priority_queue <pair<int, int>, vector<pair<int, int> >, mincmp> ();
        maxpq = priority_queue <pair<int, int>, vector<pair<int, int> >, maxcmp> ();
        vector<pair<int, int> > tmpsurvive;
        tmpsurvive = survive;
        survive = vector<pair<int, int> >();
        for(int i=0; i<tmpsurvive.size(); i++) {
            y = tmpsurvive[i].first; 
            x = tmpsurvive[i].second;
            if((y == attY) && (x == attX)) continue;
            if((y == pattY) && (x == pattX)) continue;
            if(turret[y][x] > 0) {
                survive.push_back(make_pair(y, x)); // 생존
                minpq.push(make_pair(y,x));
                maxpq.push(make_pair(y,x));

                bool flag = true;
                for(int j=0; j<track.size(); j++) {

                    if((y == track[j].first )&&(x == track[j].second)) {
                        flag = false;
                        break;
                    }
                }
                if(flag == true) {
                    cout << "정비 :"<< y<<","<<x<<" : "<< turret[y][x]<<"->"<<turret[y][x]+1<<endl;
                    turret[y][x]++; // 4. 공격과 무관한 포탑 정비 (공격력 +1)
                }
            }
        }
        if(minpq.size() == 1) { // 피공격자 == 공격자 => 종료
            cout <<" 한명남음\n";
            break;
        }
            
        cout <<"\n========\n";
        cout << k <<"번째 턴 - 공격 ("<<attY<<","<<attX<<") : "<<turret[attY][attX]<<", 피공격 ("<<pattY<<","<<pattX<<") :"<<patt<<endl;
        cout<<", 공격력 :"<<attImp <<", 1/2공격력 :"<<hatt<<endl;

        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cout << turret[i][j] << " ";
            }
            cout << endl;
        }
    }
    // 가장 높은 포탑의 공격력 출력
    int res = 0;
    for(int i=0; i<survive.size(); i++) {
        res = max(res, turret[survive[i].first][survive[i].second]);
    }
    cout << res << "\n";
    
    return 0;
}