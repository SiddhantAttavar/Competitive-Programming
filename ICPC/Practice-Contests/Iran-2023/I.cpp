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
    int n, m;
    cin >> n >> m;

    map<int, int> s, t;
    int a = 0, x = 0, res = 0;
    rep(i, 0, n) {
        int p;
        char d;
        cin >> p >> d;
        a += p;
        if (p == 0) {
            d = 'U';
        }
        else if (p == m) {
            d = 'D';
        }
        if (d == 'U') {
            s[p]++;
            x++;
        }
        else {
            t[p]++;
        }
    }
    rep(i, 0, m) {
        res = max({res, a, n * m - a});
        x -= s[m - i];
        x += t[i];
        a += x - (n - x);
        assert(a >= 0 and a <= n * m);
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
