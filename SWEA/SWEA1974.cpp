#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int sudoku[9][9];
    vector<int> num = {1,2,3,4,5,6,7,8,9};
    vector<int> tmp;
    bool result = true;
	
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case, result = true, tmp.clear())
	{
        for (int i=0; i<9; ++i) { // 스도쿠 입력
            for (int j=0; j<9; ++j) {
                cin >> sudoku[i][j];
            }
        }

        // 스도쿠 검증
        // 가로 검증
        for (int i=0; i<9; ++i, tmp.clear()) {
            for (int j=0; j<9; ++j) {
                tmp.push_back(sudoku[i][j]);
            }
            sort(tmp.begin(), tmp.end());
            if (tmp != num) {
                result = false;
                break;
            }
        }
        if (!result) {
            cout << "#" << test_case << " " <<  result << "\n";
            continue;
        }
        // 세로 검증
        tmp.clear();
        for (int i=0; i<9; ++i,tmp.clear()) {
            for (int j=0; j<9; ++j) {
                tmp.push_back(sudoku[j][i]);
            }
            sort(tmp.begin(), tmp.end());
            if (tmp != num) {
                result = false;
                break;
            }
        }
        if (!result) {
            cout << "#" << test_case <<" "<< result << "\n";
            continue;
        }
        // 3*3 검증
        tmp.clear();
        for (int i=0; i<9; i+=3) {
            for (int j=0; j<9; j+=3, tmp.clear()) {
                for (int k=i; k<i+3; ++k) 
                    for (int l=j; l<j+3; ++l) 
                        tmp.push_back(sudoku[k][l]);
                    
                sort(tmp.begin(), tmp.end());
                if (tmp != num) {
                    result = false;
                    break;
                }
            }
            if (!result)    break;
        }
        // 결과 출력
        cout << "#" << test_case << " " << result << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}