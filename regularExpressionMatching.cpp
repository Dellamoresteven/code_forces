#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.compare(p) == 0)
            return true;
    }
};

int main() {
    Solution * ans = new Solution();
    ans->isMatch("a", "ab");
}
