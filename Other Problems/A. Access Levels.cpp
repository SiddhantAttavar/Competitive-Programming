#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define endl '\n'
// #define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)((x).size()))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

const int N = 500, M = 500;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<bitset<N>> v(m, 0);
    rep(i, 0, n) {
        string s;
        cin >> s;
        rep(j, 0, m) {
            v[j][i] = s[j] == '1';
        }
    }

    vector<int> z(m);
    iota(z.begin(), z.end(), 0);
    sort(z.begin(), z.end(), [&](int a, int b) {
        rep(i, 0, n) {
            if (v[a][i] != v[b][i]) {
                return v[a][i] < v[b][i];
            }
        }
        return a < b;
    });

    vector<vi> graph(m);
    vector<bitset<M>> vis(m, 0);
    rep(i, 0, m) {
        vis[i][i] = true;
    }
	rep(i, 0, m) {
		rep(j, i + 1, m) {
			if ((v[i] & v[j]) == v[j]) {
				graph[i].push_back(j);
			}
			else if ((v[i] & v[j]) == v[i]) {
				graph[j].push_back(i);
			}
		}
	}

	vi btoa(m, -1), atob(m, -1);
	hopcroftKarp(graph, btoa);
	rep(i, 0, m) {
		if (btoa[i] != -1) {
			atob[btoa[i]] = i;
		}
	}
    
    vector<vector<int>> w;
	rep(u, 0, m) {
		if (btoa[u] != -1) {
			continue;
		}
        w.push_back({});
        int v = u;
        while (v != -1) {
            w.back().push_back(v);
            v = atob[v];
        }
    }

    vector<int> b(m), x(m);
    vector<vector<int>> res(n);
    int c = 1;
    for (vector<int> l : w) {
        if (l.empty()) {
            continue;
        }
        int t = 2;
        for (int u : l) {
            b[u] = c;
            x[u] = t;
            t++;
        }
        c++;
        
        rep(i, 0, n) {
            int s = 0, e = l.size() - 1, j = 1;
            while (s <= e) {
                int m = (s + e) / 2;
                if (v[l[m]][i]) {
                    j = m + 2;
                    s = m + 1;
                }
                else {
                    e = m - 1;
                }
            }
            res[i].push_back(j);
        }
    }

    cout << sz(w) << endl;
    for (int i : b) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i : x) {
        cout << i << ' ';
    }
    cout << endl;

    rep(i, 0, n) {
        for (int j : res[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t = 1;
	// cin >> t;
	while (t--) solve();
}

/**
3 2
01
11
10

2
1 2 
2 2 
1 2 
2 2 
2 1 

----

2 3
101
100

1
1 1 1
1 10 5
8
3
*/
