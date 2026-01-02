#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solveodd(vi &a) {
    
}

bool check(vi &a, int k) {
    int n = sz(a);
    vi c(n, 0);
    rep(i, 1, n) {
        c[i] = a[i] - (c[i - 1]);
    }
    assert(c[n - 1] + c[0] == a[0]);
    int x = 0;
    rep(i, 0, n) {
        if (i % 2 == 0) {
            x = max(x, -c[i]);
        }
        else {
            x = max(x, c[i] - k);
        }
    }
    c[0] = x;
    rep(i, 1, n) {
        c[i] = a[i] - (c[i - 1]);
    }
    assert(c[n - 1] + c[0] == a[0]);
    rep(i, 0, n) {
        if (c[i] < 0 or c[i] > k) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    if (n % 2 == 1) {
        solveodd(a);
        return;
    }

    int x = accumulate(a.begin(), a.end(), 0ll);
    int l = (x + 2 * (n - 1) - 1) / (2 * (n - 1)), r = 1e18, res = 1e18;
    l = max(l, (*max_element(a.begin(), a.end()) + 1) / 2);
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(a, m)) {
            res = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
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
