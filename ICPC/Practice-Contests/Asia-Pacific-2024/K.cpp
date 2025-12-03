#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), ecnd(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class T>
// using Tree = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;

/**
 * Author: Lucian Bicsi
 * Description: 1D point update and range query where \texttt{cmb} is
 * any associative operation. \texttt{seg[1]==query(0,N-1)}.
 * Time: O(\log N)
 * Source:
 * http://codeforces.com/blog/entry/18051
 * KACTL
 */

template <typename T>
struct SegTree
{ // cmb(ID,b) = b
    T ID;
    T (*cmb)(T a, T b);
    int n;
    vector<T> seg;
    SegTree(int _n, T id, T _cmb(T, T))
    {
        ID = id;
        cmb = _cmb;
        for (n = 1; n < _n;)
            n *= 2;
        seg.assign(2 * n, ID);
    }
    void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
    void upd(int p, T val)
    { // set val at position p
        seg[p += n] += val;
        for (p /= 2; p; p /= 2)
            pull(p);
    }
    T query(int l, int r)
    { // zero-indexed, inclusive
        T ra = ID, rb = ID;
        for (l += n, r += n + 1; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
                ra = cmb(ra, seg[l++]);
            if (r & 1)
                rb = cmb(seg[--r], rb);
        }
        return cmb(ra, rb);
    }
    pair<int, int> get(int l, int r, int u, int c = 1) {
        if (l == r) {
            return {l, u};
        }
        int m = (l + r) / 2;
        if (seg[2 * c] >= u) {
            return get(l, m, u, 2 * c);
        }
        return get(m + 1, r, u - seg[2 * c], 2 * c + 1);
    }
    /// int first_at_least(int lo, int val, int ind, int l, int r) { // if seg stores max across range
    /// 	if (r < lo || val > seg[ind]) return -1;
    /// 	if (l == r) return l;
    /// 	int m = (l+r)/2;
    /// 	int res = first_at_least(lo,val,2*ind,l,m); if (res != -1) return res;
    /// 	return first_at_least(lo,val,2*ind+1,m+1,r);
    /// }
};

void dfs1(int u, vector<vector<int>> &graph, vector<int> &s, vector<int> &ti, vector<int> &to, int &time, vector<int> &l) {
    ti[u] = time++;
    l.push_back(u);
    for (int v : graph[u]) {
        dfs1(v, graph, s, ti, to, time, l);
        s[u] += s[v];
    }
    to[u] = time - 1;
}

void dfs2(int u, vector<vector<int>> &graph, vector<int> &s, SegTree<int> &seg, vector<vector<pair<int, int>>> &z, vector<int> &res, vector<array<int, 4>> &w, vector<int> &c) {
    int n = sz(graph);
    for (auto [v, j] : z[u]) {
        auto [s, i] = seg.get(0, seg.n - 1, v + 1);
        res[j] = u * n * n + s * n;
        w.push_back({s, c[s], i, j});
    }

    for (int v : graph[u]) {
        seg.upd(v, s[v]);
        seg.upd(u, -s[v]);

        c[u] = v;
        dfs2(v, graph, s, seg, z, res, w, c);

        seg.upd(v, -s[v]);
        seg.upd(u, s[v]);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> graph(n);
    int root = -1;
    rep(i, 0, n) {
        int p;
        cin >> p;

        p--;
        if (p == -1) {
            root = i;
        }
        else {
            graph[p].push_back(i);
        }
    }

    vector<vector<pair<int, int>>> z(n);
    rep(i, 0, q) {
        int k;
        cin >> k;
        
        k--;
        z[k / n].push_back({k % n, i});
    }
    
    vi s(n, 1), ti(n), to(n), list;
    int time = 0;
    dfs1(root, graph, s, ti, to, time, list);
    
    SegTree<int> seg(n, 0, [](int a, int b) {
        return a + b;
    });
    seg.upd(root, n);
    vector<int> res(q), c(n, -1);
    vector<array<int, 4>> w;
    dfs2(root, graph, s, seg, z, res, w, c);

    // rep(i, 0, q) {
    //     cout << w[i][0] << ' ' << w[i][1] << ' ' << w[i][2] << ' ' << w[i][3] << endl;
    // }
    
    vector<int> l(q, 0), r(q, n - 1), ans(q, n);
    rep(i, 0, 20) {
        vector<vector<int>> check(n);
        rep(j, 0, q) {
            if (l[j] <= r[j]) {
                int m = (l[j] + r[j]) / 2;
                check[m].push_back(j);
            }
        }
        
        SegTree<int> seg(n, 0, [](int a, int b) {
            return a + b;
        });
        rep(j, 0, n) {
            seg.upd(ti[j], 1);
            for (int k : check[j]) {
                int x = seg.query(ti[w[k][0]], to[w[k][0]]);
                if (w[k][1] != -1) {
                    x -= seg.query(ti[w[k][1]], to[w[k][1]]);
                }
                if (x >= w[k][2]) {
                    ans[k] = j;
                    r[k] = j - 1;
                }
                else {
                    l[k] = j + 1;
                }
            }
        }
    }
    
    rep(i, 0, q) {
        // assert(w[j][2] >= 0);
        res[w[i][3]] += ans[i];
    }

    for (int i : res) {
        // cout << i / (n * n) + 1 << ' ' << (i % (n * n)) / n + 1 << ' ' << i % n + 1 << endl;
        cout << i << endl;
    }

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
}
