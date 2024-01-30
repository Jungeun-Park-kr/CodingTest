#include <iostream>
using namespace std;
int main(void) {
    int score;
    cin >> score;
    if(score >= 90) cout << "A\n";
    else if (80<=score && score < 90) cout << "B\n";
    else if (70 <= score && score < 80) cout << "C\n";
    else if (60 <= score && score < 70) cout << "D\n";
    else cout << "F\n";
    return 0;
}