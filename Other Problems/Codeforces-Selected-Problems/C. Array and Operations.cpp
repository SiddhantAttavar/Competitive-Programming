#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& inVar) {cin >> inVar;}
template<typename T, typename... S> inline void input(T& inVar, S&... args) {cin >> inVar; input(args ...);}
template<typename T> inline void print(T outVar) {cout << outVar << '\n';}
template<typename T, typename... S> inline void print(T outVar, S... args) {cout << outVar << ' '; print(args ...);}
#define int long long
#define range(it, start, end) for (auto it = start; it < end; it++)
#define arrPut(var) for (auto &inVar : var) {cin >> inVar;}
#define arrPrint(var) for (auto outVar : var) {cout << outVar << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353
#define vi vector<int>
#define sz size
#define rep range

bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(begin(btoa), end(btoa), -1);
}

const int N = 4e4;
int spf[N + 1];

int32_t main() {
	vector<int> primes;
	range(i, 0, N + 1) {
		spf[i] = i;
	}

    range(i, 2ll, N + 1) {
        if (spf[i] == i) {
			primes.push_back(i);
			for (int j = i * i; j <= N; j += i) {
				if (spf[j] == j) {
					spf[j] = i;
				}
			}
        }
    }

    setup();
	int n, m;
	input(n, m);

	vector<int> a(n);
	arrPut(a);

	vector<vector<pair<int, int>>> b(n);
	int s = 0, t = 0;
	range(i, 0, n) {
		int k = a[i];
		for (int p : primes) {
			while (k % p == 0) {
				k /= p;
				if (i % 2) {
					b[i].push_back({p, s++});
				}
				else {
					b[i].push_back({p, t++});
				}
			}
		}
		if (k > 1) {
			if (i % 2) {
				b[i].push_back({k, s++});
			}
			else {
				b[i].push_back({k, t++});
			}
		}
	}

	vector<vector<int>> graph(s);
	range(i, 0, m) {
		int u, v;
		input(u, v);

		u--;
		v--;

		if (u % 2 == 0) {
			swap(u, v);
		}

		for (pair<int, int> p : b[u]) {
			for (pair<int, int> q : b[v]) {
				if (p.first == q.first) {
					graph[p.second].push_back(q.second);
				}
			}
		}
	}

	vector<int> btoa(t, -1);
	print(dfsMatching(graph, btoa));
}
