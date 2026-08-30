#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int find(int s, int x, int c) {
    c = min(c, s - 1);
    int l = (s + 1) / 2, r = c, u = r + 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (m * (s - m) <= x) {
            u = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return c + 1 - u;
}

void solve() {
    int s, x;
    cin >> s >> x;
    
    int res = 0;
    rep(c, 1, s - 1) {
        res += find(s - c, x / c, c);
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
    cin >> t;
    while (t--) {
		solve();
	}
}
