#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

template<typename T> struct SegTree {
    T ID; T (*cmb)(T a, T b);
    int n; vector<T> seg;
    SegTree(int _n, T id, T _cmb(T, T)) {
        ID = id; cmb = _cmb;
        for (n = 1; n < _n; ) n *= 2;
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
            if (l & 1) ra = cmb(ra, seg[l++]);
            if (r & 1) rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
};

void dfs(int u, vector<vector<int>> &graph, vector<vector<int>> &p) {
    for (int v : graph[u]) {
        p[v][0] = u;
        rep(i, 1, 20) {
            if (p[v][i - 1] == -1) {
                break;
            }
            p[v][i] = p[p[v][i - 1]][i - 1];
        }
        dfs(v, graph, p);
    }
}

const int N = 1e5;
void dfs2(int u, vector<vector<int>> &graph, vector<vector<int>> &l, vector<int> &res, SegTree<int> &s, vector<int> &a, vector<int> &b) {
    for (int x : l[u]) {
        a[N]++;
        s.upd(N, a[N]);
        a[x - 1]--;
        s.upd(x - 1, a[x - 1]);
    }

    res[u] = s.query(b[u], N);
    for (int v : graph[u]) {
        dfs2(v, graph, l, res, s, a, b);
    }

    for (int x : l[u]) {
        a[N]--;
        s.upd(N, a[N]);
        a[x - 1]++;
        s.upd(x - 1, a[x - 1]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> a(n);
    rep(i, 0, n) {
        int p;
        cin >> a[i] >> p;
        if (i != p - 1) {
            graph[p - 1].push_back(i);
        }
    }

    vector<vector<int>> p(n, vector<int>(20, -1));
    dfs(0, graph, p);

    vector<vector<int>> v(n);
    while (m--) {
        int u, l, r;
        cin >> u >> l >> r;

        u--;
        for (int i = 19; i >= 0; i--) {
            if (p[u][i] != -1 and a[p[u][i]] <= r) {
                u = p[u][i];
            }
        }

        v[u].push_back(l);
    }

    vector<int> res(n, 0);
    SegTree<int> s(N + 1, 0, [](int a, int b) {
        return a + b;
    });
    vector<int> l(N + 1);
    dfs2(0, graph, v, res, s, l, a);
    for (int i : res) {
        cout << i << ' ';
    }
    cout << endl;
}
