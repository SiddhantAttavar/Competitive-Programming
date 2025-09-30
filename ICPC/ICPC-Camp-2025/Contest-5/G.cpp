#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

int p;
bool debug = false;
int s = -1;
vector<int> d;
vector<vector<int>> graph;
vector<int> siz;
void find_size(int u, int p) {
    siz[u] = 1;
    for (int v : graph[u]) {
        if (v != p) {
            find_size(v, u);
            siz[u] += siz[v];
        }
    }
}

int centroid(int u, int p, int n) {
    for (int v : graph[u]) {
        if (v != p and siz[v] > n / 2) {
            return centroid(v, u, n);
        }
    }
    return u;
}

int query(int u, int v) {
    assert(p);
    p--;
    if (debug) {
        if (d[u] < d[v]) {
            return 0;
        }
        if (d[u] == d[v]) {
            return 1;
        }
        return 2;
    }
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void dfs(int u, int p) {
    for (int v : graph[u]) {
        if (v != p) {
            d[v] = d[u] + 1;
            dfs(v, u);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc; cin >> tc; while (tc--) {
        int n;
        cin >> n;

        p = 0;
        while ((1 << (p + 1)) <= n) {
            p++;
        }

        siz.clear();
        siz.resize(n);
        graph.clear();
        graph.resize(n);
        rep(i, 0, n) {
            int u, v;
            cin >> u >> v;

            u--;
            v--;
            if (u != -1) {
                graph[i].push_back(u);
                graph[u].push_back(i);
            }
            if (v != -1) {
                graph[i].push_back(v);
                graph[v].push_back(i);
            }
        }

        if (debug) {
            cin >> s;
            s--;

            d.clear();
            d.resize(n);
            d[s] = 0;
            dfs(s, -1);
        }

        int c = 0, res = -1;
        while (res == -1) {
            find_size(c, -1);
            c = centroid(c, -1, n);
            find_size(c, -1);

            if (graph[c].size() == 0) {
                res = c;
                break;
            }

            if (graph[c].size() == 1) {
                int u = graph[c][0];
                if (query(c, u) == 0) {
                    res = c;
                }
                else {
                    res = u;
                }
                break;
            }

            int u = graph[c][0], v = graph[c][1];
            int d = 0;
            if (graph[c].size() > 2) {
                int w = graph[c][2];
                d = siz[w];
                if (d > siz[u]) {
                    swap(u, w);
                    d = siz[w];
                }
                else if (d > siz[v]) {
                    swap(v, w);
                    d = siz[w];
                }
            }
            int x = query(u, v);
            if (x == 0) {
                graph[u].erase(find(graph[u].begin(), graph[u].end(), c));
                graph[c].erase(find(graph[c].begin(), graph[c].end(), u));
                c = u;
                n = siz[u];
            }
            else if (x == 2) {
                graph[v].erase(find(graph[v].begin(), graph[v].end(), c));
                graph[c].erase(find(graph[c].begin(), graph[c].end(), v));
                c = v;
                n = siz[v];
            }
            else {
                graph[v].erase(find(graph[v].begin(), graph[v].end(), c));
                graph[c].erase(find(graph[c].begin(), graph[c].end(), u));
                graph[u].erase(find(graph[u].begin(), graph[u].end(), c));
                graph[c].erase(find(graph[c].begin(), graph[c].end(), v));
                n = d + 1;
            }
        }

        if (debug) {
            assert(res == s);
        }
        cout << "! " << res + 1 << endl;
        cout.flush();
    }
}
