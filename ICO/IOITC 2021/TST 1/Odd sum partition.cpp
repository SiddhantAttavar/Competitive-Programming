#include <bits/stdc++.h>
using namespace std; typedef long long ll; typedef vector<int> vi;
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << endl;}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define range(it, start, end) for (int it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << endl
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    setup(); int tc; input(tc); while (tc--) {
        int n; input(n);
        bool a[n];
        string s; input(s);
        range(i, 0, n) {
            a[i] = s[i] == '1';
        }

        int prefSum[n + 1] = {0};
        range(i, 0, n) {
            prefSum[i + 1] = prefSum[i] + a[i];
        }

        range(m, 1, n + 1) {
            int dp[n];
            dp[0] = a[0] ? 1 : -1;
            
            range(i, 1, n) {
                dp[i] = -1;
                if (prefSum[i + 1] % 2 == 1 && i + 1 <= m) {
                    dp[i] = 1;
                    continue;
                }
                
                range(j, 1, i + 1) {
                    if (dp[j - 1] != -1 && (prefSum[i + 1] - prefSum[j]) % 2 == 1 && (i - j + 1) <= m) {
                        if (dp[i] == -1 || dp[j - 1] + 1 < dp[i]) {
                            dp[i] = dp[j - 1] + 1;
                        }
                    }
                }                
            }

            cout << dp[n - 1] << ' ';
        }
        cout << endl;
    }
}