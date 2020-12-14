#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct player {int stam; int score;};

string solve(int a, int b) {
    if((a | b) == 0) {
        return "0 0";
    }
    player alice{a, 0};
    player bob{b, 0};
    bool is_serving = true; // true for alice, false for bob
    /*
     * if a == b
     *   if a.stam is serving and odd
     *     b.score wins by 1
     *   if b.stam is serving and odd
     *     a.score wins by 1
     *   if a.stam or b.stam is serving and even
     *     a.score = b.score = a = b
     * if a < b
     *
     * if a > b
     */
    if(alice.stam > bob.stam) {
        alice.score += alice.stam - bob.stam;
        alice.stam = bob.stam;
    }
    if(alice.stam < bob.stam) {
        bob.score += bob.stam - alice.stam;
        bob.stam = alice.stam;
    }
    if(alice.stam == bob.stam) {
        if(alice.stam % 2 == 1) {
            if(is_serving) {
                alice.score += alice.stam - 1;
                bob.score += bob.stam;
            } else {
                bob.score += bob.stam - 1;
                alice.score += alice.stam;
            }
        } else {
            alice.score += alice.stam;
            bob.score += bob.stam;
        }
    }
    string ret;
    char buffer[4];
    sprintf(buffer, "%d %d", alice.score, bob.score);

    return buffer;
}

int main() {
    int n, a, b; 
    cin >> n;
    string ret = "";
    for(size_t i = 0; i < n; i++) {
        cin >> a >> b;
        ret += solve(a,b);
        ret += "\n";
    }
    cout << ret;
}
