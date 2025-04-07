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

template<int N = 1> int solve(map<int, int> &a, int n) {
	if (n > N) {
		return solve<min(1ll << 20, 2 * N)>(a, n);
	}

	for (map<int, int>::iterator i = a.begin(); i != a.end(); i++) {
		while (i->second >= 3) {
			a[i->first * 2] += i->second / 3;
			i->second = i->second / 3 + i->second % 3;
		}
	}

	int x = 0;
	for (pair<int, int> p : a) {
		x += p.second;
	}

	if (x >= 30 or (1 << x) > n) {
		bitset<N> b = 1;
		for (pair<int, int> p : a) {
			rep(i, 0, p.second) {
				b |= b << p.first;
			}
		}

		int z = (n - 1) / 2;
		while (!b[z]) {
			z--;
		}
		return z * (n - z - 1);
	}

	set<int> s = {0};
	for (pair<int, int> p : a) {
		rep(i, 0, p.second) {
			set<int> ns(s.begin(), s.end());
			for (int j : s) {
				ns.insert(j + p.first);
			}
			s = ns;
		}
	}

	int z = *s.lower_bound((n - 1) / 2);
	return z * (n - z - 1);
}

int dfs(int u, vector<vector<int>> &graph, vector<int> &s) {
	int res = 0;
	for (int v : graph[u]) {
		res += dfs(v, graph, s);
		s[u] += s[v];
	}

	map<int, int> a;
	for (int v : graph[u]) {
		a[s[v]]++;
	}

	return res + solve(a, s[u]);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> p(n - 1);
	arrput(p);

	vector<vector<int>> graph(n);
	rep(i, 0, n - 1) {
		graph[p[i] - 1].push_back(i + 1);
	}

	vector<int> s(n, 1);
	print(dfs(0, graph, s));
}
