#include <iostream>
#include <string>
#include <vector>

using namespace std;


/*
 * https://codeforces.com/problemset/problem/1461/A
abcabcabcabcabc
*/

string solve(int a, int b) {
    if(a == 0) {
        cout << "" << endl;
    }
    string ret = "a";
    string abc = "abc";
    for(size_t i = 1; i < a; i++) {
        ret += abc.at(i%3);
    }
    return ret;
}

int main() {
    short n;
    cin >> n;
    int a,b;
    string ret = "";
    for(size_t i = 0; i < n; i++) {
        cin >> a >> b;
        ret += solve(a,b);
        ret += "\n";
    }
    cout << ret;
}
