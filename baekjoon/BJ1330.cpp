#include <iostream>
using namespace std;
int main(void) {
    int A, B;
    cin >> A >> B;
    if(A==B) cout << "==\n";
    else if (A<B) 
        cout << "<\n";
    else cout << ">\n";  // A>B
    return 0;
}
