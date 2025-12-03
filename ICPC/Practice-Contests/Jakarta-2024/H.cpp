#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

#define cff {cout.flush();}

vi Z(const string& S) {
    vi z(sz(S));
    int l = -1, r = -1;
    rep(i,1,sz(S)) {
        z[i] = i >= r ? 0 : min(r-i, z[i-l]);
        while(i + z[i] < sz(S) && S[i+z[i]] == S[z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i, r = i + z[i];
        }
    }
    return z;
}

void solve() {
    string s;
    cin >> s;

    int n = sz(s);
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {0, n}));
    vector<vector<pair<int, int>>> suff(n, vector<pair<int, int>>(n, {0, n}));
    for (int i = n - 1; i >= 0; i--) {
        vector<int> z = Z(s.substr(i));
        reverse(z.begin(), z.end());
        while (sz(z) < n) {
            z.push_back(0);
        }
        reverse(z.begin(), z.end());
        // for (int i : z) {
        //     cout << i << ' ';
        // }
        // cout << endl;

        rep(j, i, n) {
            if (j == n - 1) {
                dp[i][j] = {1, n};
                continue;
            }
            int l = min(j - i + 1, z[j + 1]);
            int k = j + 1 + l;
            if (k == n) {
                dp[i][j] = {0, n};
                continue;
            }
            if (i + l <= j and s[i + l] > s[k]) {
                dp[i][j] = {0, n};
                continue;
            }
            auto [x, u] = suff[j + 1][k];
            // cout << i << ' ' << j << ' ' << x << ' ' << u << ' ' << i - j + 1 << endl;
            dp[i][j] = {x + 1, u};
        }
        suff[i][n - 1] = {dp[i][n - 1].first, n - 1};
        for (int j = n - 2; j >= i; j--) {
            suff[i][j] = max(suff[i][j + 1], make_pair(dp[i][j].first, j));
        }
    }    

    int res = dp[0][0].first, u = 0, v = 0;
    rep(j, 0, n) {
        if (dp[0][j].first > res) {
            res = dp[0][j].first;
            v = j;
        }
    }

    cout << res << endl;
    vector<int> l;
    while (v < n) {
        l.push_back(u);
        int w = dp[u][v].second;
        u = v + 1;
        v = w;
    }
    l.push_back(n);

    rep(i, 0, sz(l) - 1) {
        cout << s.substr(l[i], l[i + 1] - l[i]) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t; // comment out if reqd.
    while (t--) {solve();}
}
