#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = a; i < b; i++)

#define sz(x) (int) x.size()
#define vi vector<int>

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		for (int y : C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
};

void dfs(int u, vector<vector<int>> &graph, vector<int> &c, vector<int> &s) {
    s[u] += graph[u].size() == 0;
    for (int v : graph[u]) {
        c[v] = c[u];
        dfs(v, graph, c, s);
        s[u] += s[v];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("gangsters.in", "r", stdin);
    freopen("gangsters.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> graph(n);
    rep(i, 0, n - 1) {
        int p;
        cin >> p;
        graph[p - 1].push_back(i + 1);
    }

    LCA l(graph);

    vector<int> c(n, -1), s(n, 0);
    for (int i : graph[0]) {
        c[i] = i;
        dfs(i, graph, c, s);
    }

    int x = 0, y = 0, res = 0;
    vector<set<int>> a(n);
    while (q--) {
        char o;
        int u;
        cin >> o >> u;
        u--;

        if (!a[c[u]].empty()) {
            if (a[c[u]].size() > 1) {
                res -= s[l.path[l.rmq.query(*a[c[u]].begin(), *a[c[u]].rbegin())]];
            }
            else {
                res--;
            }
            y--;
        }

        if (o == '+') {
            x++;
            a[c[u]].insert(l.time[u]);
        }
        else {
            x--;
            a[c[u]].erase(l.time[u]);
        }

        if (!a[c[u]].empty()) {
            if (a[c[u]].size() > 1) {
                res += s[l.path[l.rmq.query(*a[c[u]].begin(), *a[c[u]].rbegin())]];
            }
            else {
                res++;
            }
            y++;
        }

        cout << y << ' ' << res - x << endl;
    }
}
