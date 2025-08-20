#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(int l, int r, int x, int y, vector<int> &dp, vector<int> &ndp, vector<int> &p) {
    if (l > r) {
        return;
    }

    int m = (l + r) / 2;
    pair<int, int> z = {4e18, -1};
    for (int i = x; i < min(y + 1, m); i++) {
        z = min(z, {dp[i] + (p[m] - p[i]) * (m - i), i});
    }
    ndp[m] = z.first;

    solve(l, m - 1, x, z.second, dp, ndp, p);
    solve(m + 1, r, z.second, y, dp, ndp, p);
}

vector<int> dist(int b, vector<vector<pair<int, int>>> &graph) {
    vector<int> d(graph.size(), 1e18);
    d[b] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, b});
    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();

        if (x != d[u]) {
            continue;
        }

        for (auto [v, w] : graph[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
    return d;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b, s, r;
    cin >> n >> b >> s >> r;

    vector<vector<pair<int, int>>> graph(n), rev_graph(n);
    while (r--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u - 1].push_back({v - 1, w});
        rev_graph[v - 1].push_back({u - 1, w});
    }

    vector<int> x = dist(b, graph), y = dist(b, rev_graph);
    vector<int> d(b, 1e18);
    for (int i = 0; i < b; i++) {
        d[i] = x[i] + y[i];
    }
    sort(d.begin(), d.begin() + b);
    
    vector<int> p(b + 1, 0);
    for (int i = 0; i < b; i++) {
        p[i + 1] = p[i] + d[i];
    }

    vector<int> dp(b + 1, 1e18);
    for (int i = 1; i <= b; i++) {
        dp[i] = i * p[i];
    }
    for (int j = 1; j < s; j++) {
        vector<int> ndp(b + 1, 1e18);
        for (int m = 1; m <= b; m++) {
            for (int i = max(m - m / j - 1, 0ll); i < m; i++) {
                ndp[m] = min(ndp[m], dp[i] + (p[m] - p[i]) * (m - i));
            }
        }
        // solve(1, b, 0, b - 1, dp, ndp, p);
        dp = ndp;
    }
    cout << dp.back() - accumulate(d.begin(), d.end(), 0ll) << endl;
}
