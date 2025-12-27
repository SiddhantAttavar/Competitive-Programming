#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int get(string s) {
    int res = 0;
    for (char c : s) {
        res = 2 * res + (c - '0');
    }
    return res;
}

void solve() {
    set<int> l;
    rep(n, 1, 64) {
        string a = string(n, '1');
        rep(m, 1, 64) {
            string b = string(m, '0');
            string s = a;
            while (sz(s) <= 63) {
                l.insert(get(s));
                s += b + a;
            }
            s = a + b;
            while (sz(s) <= 63) {
                l.insert(get(s));
                s += a + b;
            }
        }
    }

    vector<int> v(all(l));
    int x, y;
    cin >> x >> y;
    cout << upper_bound(all(v), y) - lower_bound(all(v), x) << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    // cin >> t;
    while (t--) {
		solve();
	}
}
