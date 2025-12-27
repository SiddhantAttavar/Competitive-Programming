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

const int MOD = 1e9 + 7;
const int INV2 = (MOD + 1) / 2;

int mpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

template<class T> struct RMQ {
    vector<vector<T>> jmp;
    RMQ(const vector<T> &V) : jmp(1, V) {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k])) {
                jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
            }
        }
    }
    T query(int a, int b) { b++;
        assert(a < b);
        int dep = 31 - __builtin_clz(b - a);
        return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

int end(RMQ<int> &r, vi &l, int k, int n) {
    int s = 0, e = sz(l) - 1, u = sz(l) - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (r.query(0, m) > k) {
            u = m;
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return min(n - 1, l[u] + k);
}

int calc(vi &e, vi &p, vi &a, map<int, vi> &v, int i, int k) {
    int j = e[k];
    int x = p[j];
    if (i > j or a[i] < x) {
        return 0;
    }

    int t = lower_bound(v[x].begin(), v[x].end(), i) - v[x].begin();
    int s = lower_bound(v[x].begin(), v[x].end(), j + 1) - v[x].begin();
    int z = min(s - 1, s - t);
    return mpow(INV2, z);
}

int getk(vi &e, int i) {
    int l = 1, r = sz(e) - 1, u = sz(e) - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (e[m] >= i) {
            u = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return u;
}

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vi p(n);
    p[0] = a[0];
    rep(i, 1, n) {
        p[i] = max(p[i - 1], a[i]);
    }

    vi l;
    int x = -1;
    rep(i, 0, n) {
        if (a[i] > x) {
            x = a[i];
            l.push_back(i);
        }
    }
    
    vi d(sz(l));
    rep(i, 0, sz(l) - 1) {
        d[i] = l[i + 1] - l[i];
    }
    d.back() = n - l.back();
    RMQ r(d);
    
    vi e(n + 1);
    rep(k, 1, n + 1) {
        e[k] = end(r, l, k, n);
    }

    map<int, vi> v;
    rep(i, 0, n) {
        v[a[i]].push_back(i);
    }

    while (q--) {
        int o, i;
        cin >> o >> i;

        i--;
        int k;
        if (o == 1) {
            cin >> k;
        }
        else {
            k = getk(e, i);
            cout << k << ' ';
        }
        cout << calc(e, p, a, v, i, k) << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}
