#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSpecialChars(string s) {
        map<int, int> m;
        for (int i = 0; i < s.size(); i++) {
            if ('a' <= s[i] and s[i] <= 'z') {
                m[s[i]] = i;
            }
            else if (!m.count(s[i])) {
                m[s[i]] = i;
            }
        }
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += m.count('a' + i) and m.count('A' + i) and m['a' + i] < m['A' + i];
        }
        return res;
    }
};
