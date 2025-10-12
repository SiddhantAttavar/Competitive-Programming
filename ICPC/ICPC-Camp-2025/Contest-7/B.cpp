#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define ll long long
#define vi vector<int>
#define sz(x) (int) x.size()

struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() {
            return max(oc - c, 0ll);
        }
    };

    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int &i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1) {
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
            }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L, 0, 31) do {
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe and !lvl[t]) {
                int v = q[qi++];
                for (Edge &e : adj[v]) {
                    if (!lvl[e.to] && e.c >> (30 - L)) 
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
                }
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, c, d;
    cin >> n >> m >> c >> d;

    int t = 0;
    Dinic dinic(n + m + 2);
    rep(i, 0, n) {
        dinic.addEdge(0, i + 1, 0);
    }
    rep(j, 0, m) {
        dinic.addEdge(j + n + 1, n + m + 1, 0);
    }
    int empty = 0;
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, m) {
            if (s[j] == '.') {
                empty++;
                dinic.addEdge(i + 1, j + n + 1, 1);
            }
        }
    }
    
    int res = empty * d, f = 0;
    rep(k, 1, max(n, m) + 1) {
        for (Dinic::Edge &i : dinic.adj[0]) {
            i.c++;
        }
        rep(j, 0, m) {
            dinic.adj[j + n + 1][0].c++;
        }
        f += dinic.calc(0, n + m + 1);
        res = min(res, c * k + d * (empty - f));
    }
    cout << res << endl;
}
