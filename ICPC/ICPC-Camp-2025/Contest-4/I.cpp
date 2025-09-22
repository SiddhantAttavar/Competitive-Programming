#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define vi vector<int>
#define sz(x) (int) x.size()

vector<vector<pair<int, int>>> decomp;
vector<vi> adj; vi siz;
vector<bool> vis;
void find_size(int v, int p) {
	siz[v] = 1;
	for(auto nx : adj[v]) if(nx != p && !vis[nx]) {
		find_size(nx, v);
		siz[v] += siz[nx];
	}
}
int centroid(int v, int p, int n) {
	for(auto nx : adj[v]) if(nx != p && !vis[nx] && siz[nx] > n/2) {
		return centroid(nx, v, n);
	}
	return v;
}
void process(int v) {}
int solve(int v, int p) {
	find_size(v, p);
	int c = centroid(v, p, siz[v]);
	process(c);
	vis[c] = true;
	for(auto nx : adj[c]) if(!vis[nx]) decomp[c].push_back({solve(nx, c), nx});
	return c;
}

int u = -1;
vector<int> dist;
int max_queries = 0;

void dfs(int u, int p, vector<vector<int>> &graph, vector<int> &d) {
    for (int v : graph[u]) {
        if (v != p) {
            d[v] = d[u] + 1;
            dfs(v, u, graph, d);
        }
    }
}

void dfs2(int u, vector<vector<pair<int, int>>> &graph, vector<int> &s) {
    for (auto [v, w] : graph[u]) {
        dfs2(v, graph, s);
        s[u] += s[v];
    }
}

void preprocess() {
    dist.resize(adj.size());
    dist[u] = 0;
    dfs(u, -1, adj, dist);
}

int query(int x, vector<int> &v) {
    if (v.empty()) {
        return true;
    }
    // assert(max_queries);
    max_queries--;
    if (u == -1) {
        cout << "? " << v.size() << ' ' << x + 1 << '\n';
        for (int i : v) {
            cout << i + 1 << ' ';
        }
        cout << endl;
        cout.flush();
        int ans;
        cin >> ans;
        return ans;
    }
    for (int i : v) {
        if (dist[i] < dist[x]) {
            return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vis.resize(n, false);
    siz.resize(n, 0);
    decomp.resize(n);
    
    vector<vector<int>> graph(n);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;

        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }
    adj = graph;

    max_queries = 0;
    while ((1 << max_queries) < n) {
        max_queries++;
    }
    max_queries *= 4;
    // cin >> u;
    // u--;
    // preprocess();

    int x = solve(0, 0);
    vector<int> cent_size(n, 1);
    dfs2(x, decomp, cent_size);
    while (true) {
        vector<pair<int, int>> s;
        vector<int> t;
        for (auto [v, w] : decomp[x]) {
            s.push_back({cent_size[v], w});
            t.push_back(w);
        }

        if (query(x, t)) {
            cout << "! " << x + 1 << endl;
            return 0;
        }

        int l = 0, r = s.size() - 1, y = s.size() - 1;
        while (l < r) {
            int z = 0;
            rep(i, l, r + 1) {
                z += s[i].first;
            }
            int m = l, sum = s[l].first, best = abs(z - 2 * s[l].first);
            rep(i, l + 1, r + 1) {
                sum += s[i].first;
                if (abs(z - 2 * sum) < best) {
                    best = abs(z - 2 * sum);
                    m = i;
                }
            }
            vector<int> query_list;
            rep(i, 0, m + 1) {
                query_list.push_back(s[i].second);
            }
            if (query(x, query_list)) {
                l = m + 1;
                y = m + 1;
            }
            else {
                y = m;
                r = m;
            }
        }

        x = decomp[x][y].first;
    }
}
