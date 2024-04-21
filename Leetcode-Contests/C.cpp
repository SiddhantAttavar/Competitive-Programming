#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<vector<int>>& a) {
        vector<vector<int>> v(a[0].size(), vector<int>(10, 0));
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < a[i].size(); j++) {
                v[j][a[i][j]]++;
            }
        }
        
        vector<vector<int>> dp(a[0].size(), vector<int>(10, 1e9));
        for (int j = 0; j < 10; j++) {
            dp[0][j] = a.size() - v[0][j];
        }
        for (int i = 1; i < a[0].size(); i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = 0; k < 10; k++) {
                    if (j != k) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + (int) a.size() - v[i][j]);
                    }
                }
            }
        }
        return *min_element(dp[a[0].size() - 1].begin(), dp[a[0].size() - 1].end());
    }
};
