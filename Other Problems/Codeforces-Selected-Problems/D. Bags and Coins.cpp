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

void dfs(int u, vector<vector<int>> &graph, vector<int> &c) {
	for (int v : graph[u]) {
		dfs(v, graph, c);
		c[u] += c[v];
	}
}

bool check(vector<int> &a, int s, vector<pair<int, vector<int>>> &res) {
	int n = a.size();
	vector<vector<int>> graph(n);
	vector<int> c(n);
	vector<bool> b(n, true);
	rep(u, 0, n) {
		c[u] = res[u].first;
		for (int v : res[u].second) {
			graph[u].push_back(v - 1);
			b[v - 1] = false;
		}
	}
	rep(u, 0, n) {
		if (b[u]) {
			dfs(u, graph, c);
			s -= c[u];
		}
	}
	rep(i, 0, n) {
		if (c[i] != a[i]) {
			return false;
		}
	}
	return s == 0;
}

const int N = 70001;
template<int l = 1>
vector<int> get(vector<int> &a, int x) {
	if (l < x) {
		return get<min(2 * l, N)>(a, x);
	}

	vector<bitset<l>> dp(a.size() + 1);
	dp[0] = 1;
	rep(i, 0, a.size()) {
		dp[i + 1] = dp[i] | (dp[i] << a[i]);
	}

	vector<int> res;
	int u = x, i = a.size();
	while (u > 0 and i > 0) {
		i--;
		if (!dp[i][u]) {
			res.push_back(i);
			u -= a[i];
		}
	}
	return res;
}

bitset<N> solve(vector<int> &a) {
	bitset<N> dp = 1;
	for (int i : a) {
		dp |= dp << i;
	}
	return dp;
}

int32_t main() {
	setup();

	int n, s;
	input(n, s);

	vector<int> a(n);
	arrput(a);

	vector<pair<int, int>> v(n);
	rep(i, 0, n) {
		v[i] = {a[i], i};
	}
	sort(v.begin(), v.end());

	const int N = 70000;
	vector<int> p(N + 1, -1);
	bitset<N + 1> dp = 1;
	rep(i, 0, n - 1) {
		bitset<N + 1> ndp = dp | (dp << v[i].first);
		bitset<N + 1> y = ndp ^ dp;
		int j = y._Find_first();
		while (j < N + 1) {
			p[j] = i;
			j = y._Find_next(j);
		}
		dp = ndp;
	}

	if (s < v[n - 1].first or !dp[s - v[n - 1].first]) {
		print(-1);
		return 0;
	}

	vector<bool> b(n, false);
	int u = s - v[n - 1].first, i = n - 1;
	while (u > 0) {
		i = p[u];
		u -= v[i].first;
		b[v[i].second] = true;
	}

	int j = -1;
	vector<pair<int, vector<int>>> res(n);
	rep(i, 0, n) {
		if (b[v[i].second]) {
			res[v[i].second] = {v[i].first, {}};
			continue;
		}

		if (j == -1) {
			res[v[i].second] = {v[i].first, {}};
		}
		else {
			res[v[i].second] = {v[i].first - v[j].first, {v[j].second + 1}};
		}
		j = i;
	}

	for (auto [c, v] : res) {
		cout << c << ' ' << v.size() << ' ';
		arrprint(v);
	}
	// assert(check(a, s, res));
}
