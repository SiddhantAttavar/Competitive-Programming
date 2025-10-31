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
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

int32_t main() {
	const int N = 1e7;
	vector<bool> seive(N + 1, true);
	vector<int> p;
	rep(i, 2, N + 1) {
		if (!seive[i]) {
			continue;
		}
		p.push_back(i);
		for (int j = i; j <= N; j += i) {
			seive[j] = false;
		}
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		if (n == 2) {
			print(1, 1);
			continue;
		}

		int k = 0;
		while (k * (k + k % 2) / 2 + 1 - k % 2 < n - 1) {
			k++;
		}

		vector<vector<pair<int, int>>> graph(k);
		int t = 0;
		rep(i, 0, k) {
			rep(j, 0, i - 1) {
				graph[i].push_back({j, t});
				graph[j].push_back({i, t});
				t++;
			}
			if (i and (k % 2 or i % 2)) {
				graph[i].push_back({i - 1, t});
				graph[i - 1].push_back({i, t});
				t++;
			}
		}

		vector<int> v = eulerWalk(graph, t, 0);
		vector<bool> b(n, false);
		vector<int> res;
		for (int i : v) {
			res.push_back(p[i]);
			if (res.size() == n) {
				break;
			}
			if (!b[i]) {
				b[i] = true;
				res.push_back(p[i]);
			}
			if (res.size() == n) {
				break;
			}
		}
		arrprint(res);
	}
}
