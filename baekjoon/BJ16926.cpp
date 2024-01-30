#include <iostream>
using namespace std;
int N, M, R, depth;
int a[301][301], b[301][301];

void dfs() {
	for (int start = 0; start < depth; start++) {
		int r = start;
		int c = start;
        int pre = a[r][c];
		//왼쪽
		while (r < N - 1 - start) {
			int nextVal = a[r + 1][c];
			a[r + 1][c] = pre;
			pre = nextVal;
			r++;
		}
		//바닥
		while (c < M-1-start) {
			int nextVal = a[r][c + 1];
			a[r][c + 1] = pre;
			pre = nextVal;
			c++;
		}
		//오른쪽
		while (r>=1+start) {
			int nextVal = a[r - 1][c];
			a[r - 1][c] = pre;
			pre = nextVal;
			r--;
		}
		//위
		while (c>=1+start) {
			int nextVal = a[r][c - 1];
			a[r][c - 1] = pre;
			pre = nextVal;
			c--;
		}
	}
}


int main(void) {
    cin >> N >> M >> R;
    for(int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cin >> a[i][j];
        }
    }
    if(N < M) depth = (N/2)+(N%2);
    else depth = (M/2)+(M%2);
    for(int r=0; r<R; r++) {
        dfs();
        
        cout << "==================\n";
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}