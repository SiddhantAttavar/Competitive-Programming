/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define sz(x) ((ll)((x).size()))

constexpr ll inf = 1E18;
const ll mod = 1000000007;

void norm(ll& a, ll mod) {
    if(a < -mod || a >= mod) {
        a %= mod;
    }
    if(a < 0) {
        a += mod;
    }
}

void add(ll& a, ll b) {
    norm(a);
    norm(b);
    a += b;
    norm(a);
}
void mul(ll &a, ll b) {
    norm(a);
    norm(b);
    a *= b;
    norm(a);
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> g(n+1);
    ll s, t, L; cin >> s >> t >> L;

    vector<array<ll, 3>> edges;

    for(ll i = 0; i < m; i++) {
        ll u, v, wt; cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
        edges.push_back({v, u, wt});
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }   




    
    function<void(ll, vector<ll>&, vector<ll>&)> opt_ways = [&](ll src, vector<ll>& dist, vector<ll>& ways) -> void {

        multiset<pair<ll, ll>> st;
        st.insert({0, src});
        dist[src] = 0;
        ways[src] = 1;
        while(st.empty() == false) {
            auto [curr_dist, v] = *st.begin();
            st.erase(st.begin());
            for(auto [x, wt] : g[v]) {
                if(curr_dist + wt < dist[x]) {
                    dist[x] = curr_dist + wt;

                    ways[x] = ways[v];
                    st.insert({dist[x], x});
                } else if (curr_dist + wt == dist[x]) {
                    // dist[x] = curr_dist + wt;
                    // ways[x] += ways[v];
                    add(ways[x], ways[v]);

                } else {

                }
            }
        }


    };

    // cout << s << " " << t << " " << L << endl=;


    vector<ll> ds(n+1, inf);
    vector<ll> ways_s(n+1, 0);
    opt_ways(s, ds, ways_s);

    vector<ll> dt(n+1, inf);
    vector<ll> ways_t(n+1);
    opt_ways(t, dt, ways_t);


    // for(ll i = 1; i <= n; i++) {cout << ds[i] << " ";}
    // cout << endl;
    // for(ll i = 1; i <= n; i++) {cout << dt[i] << " ";}
    // cout << endl;
    // for(ll i = 1; i <= n; i++) {cout << ways_s[i] << " ";}
    // cout << endl;
    // for(ll i = 1; i <= n; i++) {cout << ways_t[i] << " ";}
    // cout << endl;

    ll ans = 0;
    ll opt = ds[t];

    if(L == opt) {
        cout << ways_s[t] << endl;
        return;
    }

    for(auto [a,b,wt] : edges) {
        ll u = a, v = b;

        if(u != t and ds[u] + dt[u] == opt and ds[u] + dt[v] + wt == L) {

            // cout << u << " " << v << " " << wt << endl;
            ll temp = ways_s[u];
            mul(temp, ways_t[v]);

            add(ans, temp);
        }
    }

    cout << ans << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)
const int MOD = 1e9 + 7;

void get(int s, vector<int> &d, vector<int> &dp, vector<vector<pair<int, int>>> &graph) {
    d[s] = 0;
    dp[s] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();

        if (x != d[u]) {
            continue;
        }

        for (auto [v, w] : graph[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                dp[v] = dp[u];
                pq.push({d[v], v});
            }
            else if (d[u] + w == d[v]) {
                dp[v] = (dp[v] + dp[u]) % MOD;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int s, t, l;
    cin >> s >> t >> l;
    s--;
    t--;

    vector<vector<pair<int, int>>> graph(n);
    rep(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        graph[v - 1].push_back({u - 1, w});
    }

    vector<int> x(n, 1e18), a(n, 0), y(n, 1e18), b(n, 0);
    get(s, x, a, graph);
    get(t, y, b, graph);

    if (x[t] == l) {
        cout << a[t] << endl;
        return 0;
    }

    int res = 0;
    rep(u, 0, n) {
        if (x[u] + y[u] != x[t] or u == t) {
            continue;
        }
        for (auto [v, w] : graph[u]) {
            if (x[u] + w + y[v] == l) {
                res = (res + a[u] * b[v]) % MOD;
            }
        }
    }
    cout << res << endl;
}
