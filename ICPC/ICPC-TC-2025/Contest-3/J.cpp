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
    vector<pair<int, int>> a(10);
    rep(i, 0, 10) {
        cin >> a[i].first >> a[i].second;
    }
    vector<array<int, 3>> v(10);
    rep(i, 0, 10) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    int c = 0;
    rep(j, 0, 3) {
        rep(i, 0, 10) {
            int k = max(0ll, (c - v[i][2]) / (v[i][0] + v[i][1]));
            v[i][2] += (v[i][0] + v[i][1]) * k;
            if (v[i][2] <= c) {
                c = max(c, v[i][2] + v[i][0]);
                v[i][2] += v[i][0] + v[i][1];
            }
            v[i][2] = max(v[i][2], c + a[i].first);
            c += a[i].first + a[i].second;
        }
    }
    cout << c - a[9].second << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
