#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

pair<int, int> prev(char c) {
    pair<int, int> x = {0, 0};
    if (c == 'L') {
        x.first++;
    }
    else if (c == 'R') {
        x.first--;
    }
    else if (c == 'U') {
        x.second--;
    }
    else {
        x.second++;
    }
    return x;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> v = {{0, 0}};
    map<pair<int, int>, vector<int>> m;
    m[{0, 0}] = {0};
    int x = 0, y = 0, t = 0;
    string s;
    cin >> s;
    for (char c : s) {
        if (c == 'L') {
            x--;
        }
        else if (c == 'R') {
            x++;
        }
        else if (c == 'U') {
            y++;
        }
        else {
            y--;
        }
        t++;
        m[{x, y}].push_back(t);
        v.push_back({x, y});
    }

    map<pair<int, int>, vector<pair<int, int>>> precomp;
    precomp[{0, -1}].resize(n + 1, {0, -1});
    precomp[{0, 1}].resize(n + 1, {0, 1});
    precomp[{1, 0}].resize(n + 1, {1, 0});
    precomp[{-1, 0}].resize(n + 1, {-1, 0});
    for (int i = n - 1; i >= 0; i--) {
        for (auto &[p, _] : precomp) {
            pair<int, int> q = {v[i].first - p.first, v[i].second - p.second};
            if (!m.count(q) or m[q].back() <= i) {
                precomp[p][i] = {v[n].first - q.first, v[n].second - q.second};
            }
            else {
                int j = *lower_bound(m[q].begin(), m[q].end(), i + 1);
                precomp[p][i] = precomp[prev(s[j - 1])][j];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        pair<int, int> q = {-a, -b};
        if (!m.count(q)) {
            cout << a + v[n].first << ' ' << b + v[n].second << endl;
        }
        else {
            int j = m[q][0];
            pair<int, int> res = precomp[prev(s[j - 1])][j];
            cout << res.first << ' ' << res.second << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; while (t--) {
        solve();
    }
}
