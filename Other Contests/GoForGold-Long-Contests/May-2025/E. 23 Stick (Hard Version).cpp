#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

#define vi vector<int>
#define pii pair<int, int>
#define sz(x) (int) x.size()

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}
	}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	reverse(ret.begin(), ret.end());
	return ret;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vector<vector<pair<int, int>>> graph(n);
		int c = 0;
		rep(i, 0, n - 2) {
			graph[i].push_back({i + 2, c});
			graph[i + 2].push_back({i, c});
			c++;
		}
		rep(i, 0, n - 3) {
			graph[i].push_back({i + 3, c});
			graph[i + 3].push_back({i, c});
			c++;
		}

		vector<int> res = eulerWalk(graph, c);
		if (res.empty()) {
			res = eulerWalk(graph, c, 1);
		}
		if (res.empty() and n > 2) {
			res = eulerWalk(graph, c, 2);
		}
		if (res.empty() and n > 3) {
			res = eulerWalk(graph, c, 3);
		}
		if (res.empty()) {
			print(-1);
			continue;
		}

		rep(i, 0, res.size()) {
			res[i]++;
		}
		arrprint(res);
	}
}
