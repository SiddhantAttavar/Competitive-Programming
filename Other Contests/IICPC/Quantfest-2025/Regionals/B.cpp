#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<int, int> s;
    rep(i, 1, n + 1) {
        for (int j = i; j <= n; j += i) {
            s[i]++;
        }
    }

    vector<pair<int, int>> l;
    for (auto [k, v] : s) {
        int z = k;
        for (int i = 0; i < 20; i++) {
            if (v >> i & 1) {
                l.push_back({k, z});
            }
            z = z * z % MOD;
        }
    }

    vector<int> dp(n + 1, 1);
    for (auto [a, b] : l) {
        for (int j = 0; )
    }
}
