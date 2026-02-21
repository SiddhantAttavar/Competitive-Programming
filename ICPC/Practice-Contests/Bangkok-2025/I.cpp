#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool get(int k, string &s, vector<array<int, 4>> &res) {
    res.clear();
    int n = sz(s);
    vector<pii> x, y;
    int l = 0;
    rep(i, 0, n) {
        if (s[i] != 'I') {
            continue;
        }
        while (l < n and (s[l] != 'C' or l < i)) {
            l++;
        }
        if (l < n) {
            x.push_back({i, l});
            l++;
        }
        if (sz(x) == k) {
            break;
        }
    }
    vi v(n, false);
    for (auto [i, j] : x) {
        v[i] = true;
        v[j] = true;
    }

    int r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != 'C' or v[i]) {
            continue;
        }
        
        while (r >= 0 and (s[r] != 'P' or r > i)) {
            r--;
        }
        if (r >= 0) {
            y.push_back({r, i});
            r--;
        }
        if (sz(y) == k) {
            break;
        }
    }
    reverse(all(y));

    if (k > min(sz(x), sz(y))) {
        return false;
    }

    rep(i, 0, k) {
        res.push_back({x[i].first, x[i].second, y[i].first, y[i].second});
    }
    
    for (auto [i, j, k, l] : res) {
        if (i >= j or j >= k or k >= l or s[i] != 'I' or s[j] != 'C' or s[k] != 'P' or s[l] != 'C') {
            return false;
        }
    }
    return true;
}

void solve() {
    string s;
    cin >> s;

    vector<array<int, 4>> res;
    int l = 0, r = sz(s) / 4, u = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (get(m, s, res)) {
            u = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    assert(get(u, s, res));

    cout << u << endl;
    for (auto [i, j, k, l] : res) {
        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << ' ' << l + 1 << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
