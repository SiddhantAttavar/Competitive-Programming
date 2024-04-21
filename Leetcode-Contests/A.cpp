#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string s) {
        	set<char> a(s.begin(), s.end());

            int res = 0;
            for (int i = 0; i < 26; i++) {
                res += a.count('a' + i) & a.count('A' + i);
            }
        
            return res;
    }
};
