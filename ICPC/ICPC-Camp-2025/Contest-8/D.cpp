#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((ll)((x).size()))
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DSU {
vi e;
    DSU(int n) : e(n, -1) {}
    bool sameSet(int a, int b) { return find(a) == find(b); }
    int size(int x) { return -e[find(x)]; }
    int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
    bool join(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        return true;
    }
};

void solve() {
    // cout << "hi" << endl;
    ll n, m; cin >> n >> m;
    vector<array<ll, 3>> edges;
    DSU dsu(n+1);

    for(ll i = 0; i < m; i++) {
        ll u, v, wt; cin >> u >> v >> wt;
        edges.push_back({wt, u, v});
    }

    sort(edges.begin(), edges.end());
    reverse(all(edges));

    // DSU dsu(n+1);

    ll ans = 0;

    for(ll i = 0; i < m; ) {
        ll j = i;
        while(j+1 < m && edges[j+1][0] == edges[i][0]) {
            j++;
        }

        // [i, j] edge indices have same weights.
        ll wt = edges[i][0];

        for(ll k = i; k <= j; k++) {
            if(dsu.sameSet(edges[k][1], edges[k][2]) == true) {
                cout << -1 << endl;
                return;
            }
        }

        for(ll k = i; k <= j; k++) {
            if(dsu.sameSet(edges[k][1], edges[k][2])) { continue; }
            ans += wt * dsu.size(edges[k][1]) *  dsu.size(edges[k][2]);
            dsu.join(edges[k][1], edges[k][2]);
        }

        i = j+1;
    }

    for(ll i = 2; i <= n; i++) {
        if(dsu.sameSet(1, i)) { continue; }
        ans += 1 * dsu.size(1) * dsu.size(i);
        dsu.join(1, i);
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}
