#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    vector<pii> v;
    vi a(10);
    iota(all(a), 0);
    rep(i, 0, 9) {
        rep(j, 0, 5) {
            v.push_back({a[j], a[9 - j]});
        }
        a.insert(a.begin() + 1, a.back());
        a.pop_back();
    }

    int k;
    cin >> k;

    string s;
    cin >> s;

    vi x(10, 0);
    rep(i, 0, k) {
        if (s[i] == '1') {
            x[v[i].first]++;
        }
        else {
            x[v[i].second]++;
        }
    }

    int n = 45 - k;
    if (x[0] + n / 5 >= 5) {
        cout << "YES\n";
        return;
    }

    rep(i, 0, 1 << n) {
        vi y = x;
        rep(j, 0, n) {
            if (i >> j & 1) {
                y[v[j + k].first]++;
            }
            else {
                y[v[j + k].second]++;
            }
        }
        int c = 0;
        rep(j, 1, 10) {
            c += y[j] > y[0];
        }
        if (c < 4) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
