#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define sz(x) (int) x.size()

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
    int low = val[j] = ++Time, x; z.push_back(j);
    for (auto e : g[j]) if (comp[e] < 0) {
        low = min(low, val[e] ?: dfs(e, g, f));
    }

    if (low == val[j]) {
        do {
            x = z.back();
            z.pop_back();
            comp[x] = ncomps;
            cont.push_back(x);
        } while (x != j);
        f(cont);
        cont.clear();
        ncomps++;
    }
    return val[j] = low;
}

template<class G, class F> void scc(G &g, F &f) {
    int n = sz(g);
    val.assign(n, 0);
    comp.assign(n, -1);
    Time = ncomps = 0;
    rep(i, 0, n) if (comp[i] < 0) dfs(i, g, f);
}

template<typename T> struct SegTree {
    T ID; T (*cmb)(T a, T b);
    int n; vector<T> seg;
    SegTree(int _n, T id, T _cmb(T, T)) {
        ID = id; cmb = _cmb;
        for (n = 1; n < _n; n *= 2) n *= 2;
        seg.assign(2 * n, ID);
    }
    void pull(int p) {
        seg[p] = cmb(seg[2 * p], seg[2 * p + 1]);
    }
    void upd(int p, T val) {
        seg[p += n] = val;
        for (p /= 2; p; p /= 2) pull(p);
    }
    T query(int l, int r) {
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = cmb(ra, seg[l++]);
            if (r&1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("codecoder.in", "r", stdin);
    freopen("codecoder.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    rep(i, 0, n) {
        cin >> a[i].first >> a[i].second;
    }

    vector<pair<int, int>> x(n), y(n);
    rep(i, 0, n) {
        x[i] = {a[i].first, i};
        y[i] = {a[i].second, i};
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    vector<vector<int>> graph(n);
    rep(i, 0, n) {
        int j = lower_bound(x.begin(), x.end(), make_pair(a[i].first, -1ll)) - x.begin() - 1;
        if (j >= 0) {
            graph[i].push_back(x[j].second);
        }
        j = lower_bound(y.begin(), y.end(), make_pair(a[i].second, -1ll)) - y.begin() - 1;
        if (j >= 0) {
            graph[i].push_back(y[j].second);
        }
    }
    // rep(i, 0, n) {
    //     cout << i << ": ";
    //     for (int j : graph[i]) {
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    vector<pair<int, int>> dp(a.begin(), a.end());
    auto func = [&](vi &l) {
        int x = 0, y = 0;
        // cout << "debug\n";
        for (int u : l) {
            // cout << u << ' ';
            x = max(x, a[u].first);
            y = max(y, a[u].second);
            for (int v : graph[u]) {
                x = max(x, dp[v].first);
                y = max(y, dp[v].second);
            }
        }
        // cout << endl;
        for (int u : l) {
            dp[u] = {x, y};
        }
    };
    scc(graph, func);
    // rep(i, 0, n) {
    //     cout << comp[i] << ' ';
    // }
    // cout << endl;

    // rep(i, 0, n) {
    //     cout << dp[i].first << ' ' << dp[i].second << endl;
    // }

    int N = 1e6;
    vector<vector<pair<int, int>>> v(N + 1);
    vector<vector<int>> w(N + 1);
    rep(i, 0, n) {
        v[dp[i].first].push_back({dp[i].second, i});
        w[a[i].first].push_back(a[i].second);
        // cout << a[i].first << ' ' << a[i].second << endl;
        // cout << dp[i].first << ' ' << dp[i].second << endl;
    }
    
    SegTree<int> s(N + 1, 0, [](int a, int b) {
        return a + b;
    });
    vector<int> t(N + 1, 0);
    vector<int> res(n);
    rep(i, 0, N + 1) {
        sort(w[i].begin(), w[i].end());
        for (auto [y, j] : v[i]) {
            res[j] = s.query(0, y) + (lower_bound(w[i].begin(), w[i].end(), y) - w[i].begin());
        }
        for (int j : w[i]) {
            t[j]++;
            s.upd(j, t[j]);
        }
    }
    rep(i, 0, n) {
        res[i] -= a[i] < dp[i];
        cout << res[i] << endl;
    }
}
