#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void even(vector<vi> &a) {
    int n = sz(a), m = sz(a[0]);
    vi v(n, true);
    rep(i, 0, n) {
        if (!v[i]) {
            continue;
        }
        rep(j, 0, n) {
            if (a[i] == a[j]) {
                v[j] = false;
            }
        }
        rep(j, 0, m) {
            cout << a[i][j] << ' ';
        }
    }
    cout << endl;
}

void odd(vector<vi> &a) {
    int n = sz(a), m = sz(a[0]);
    vi v(n, -1);
    rep(i, 0, n) {
        rep(j, 0, n) {
            bool flag = true;
            rep(k, 0, m / 2) {
                if (a[i][k] != a[j][k + m / 2]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                v[i] = j;
            }
        }
    }
    vi l(n);
    int u = 0, j = 0;
    rep(i, 0, n) {
        l[j] = u;
        u = v[u];
        j = (j + n / 2) % n;
    }
    rep(i, 0, n / 2) {
        rep(j, 0, m) {
            cout << a[l[i]][j] << ' ';
        }
    }
    rep(j, 0, m / 2) {
        cout << a[l[n / 2]][j] << ' ';
    }
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vi> a(n, vi(m));
    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> a[i][j];
        }
    }

    if (n % 2 == 0) {
        even(a);
    }
    else {
        odd(a);
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
