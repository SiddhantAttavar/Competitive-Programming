#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi solve(vi &a, int k) {
    int n = sz(a);
    vi v(k, n), l(n + 1, n - 1);
    int u = n;
    for (int i = n - 1; i >= 0; i--) {
        if (v[a[i]] < n) {
            u = min(u, v[a[i]]);
        }
        v[a[i]] = i;
        l[i] = u - 1;
    }
    
    rep(i, 0, n) {
        if (l[i] == i + k - 1) {
            return {n * (n + 1) / 2};
        }
    }

    u = -1;
    set<int> s;
    v.assign(n, -1);
    vi res(n, -1);
    rep(i, 0, n) {
        while (u < l[i + 1]) {
            u++;
            if (v[a[u]] != -1) {
                s.erase(v[a[u]]);
            }
            v[a[u]] = u;
            s.insert(u);
        }
        if (sz(s) == k) {
            res[i] = *s.begin();
        }
    }
    return res;
}

void solve() {
	int n, k;
    cin >> n >> k;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
        a[i]--;
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vi b = a;
    reverse(all(b));
    vi rtol = solve(a, k), ltor = solve(b, k);
    if (sz(rtol) == 1) {
        cout << rtol[0] << endl;
        return;
    }
    reverse(all(ltor));
    rep(i, 0, n) {
        ltor[i] = n - 1 - ltor[i];
    }

    // for (int i : rtol) cout << i << ' ';
    // cout << endl;
    // for (int i : ltor) cout << i << ' ';
    // cout << endl;

    rep(i, 0, n) {
        if (ltor[i] < n) {
            rtol[ltor[i]] = max(rtol[ltor[i]], i);
        }
    }
    rep(i, 1, n) {
        rtol[i] = max(rtol[i], rtol[i - 1]);
    }

    int res = 0;
    for (int i : rtol) {
        res += i + 1;
    }
    cout << res << endl;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
}
