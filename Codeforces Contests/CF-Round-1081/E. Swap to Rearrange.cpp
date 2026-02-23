#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
#define debug(...) cout << #__VA_ARGS__ << ": "; print(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

vector<array<int, 3>> eulerWalk(vector<vector<pii>>& gr, int nedges, vi &src) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), s = src;
	vector<array<int, 3>> ret;
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
			ret.push_back({x, y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges) return {};
	return {ret.rbegin(), ret.rend()};
}

void dfs(int u, vector<vector<pii>> &graph, vi &vis) {
	vis[u] = true;
	for (auto [v, i] : graph[u]) {
		if (!vis[v]) {
			dfs(v, graph, vis);
		}
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);
		
		vi a(n), b(n);
		arrput(a);
		arrput(b);

		vi res(n, false);
		vector<vector<pii>> graph(n);
		vi v;
		rep(i, 0, n) {
			if (a[i] == b[i]) {
				continue;
			}
			if (a[i] > b[i]) {
				swap(a[i], b[i]);
				res[i] = true;
			}
			a[i]--;
			b[i]--;
			graph[a[i]].push_back({b[i], sz(v)});
			graph[b[i]].push_back({a[i], sz(v)});
			v.push_back(i);
		}

		if (v.empty()) {
			print(0);
			continue;
		}

		vi vis(n, false), s;
		rep(i, 0, n) {
			if (!vis[i]) {
				dfs(i, graph, vis);
				s.push_back(i);
			}
		}
		vector<array<int, 3>> p = eulerWalk(graph, sz(v), s);
		if (p.empty()) {
			print(-1);
			continue;
		}

		for (auto [x, y, i] : p) {
			if (x > y) {
				res[v[i]] = !res[v[i]];
			}
		}
		print(accumulate(all(res), 0ll));
		rep(i, 0, n) {
			if (res[i]) {
				cout << i + 1 << ' ';
			}
		}
		cout << endl;
	}
}
