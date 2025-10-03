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

bool debug = false;
vector<int> perm;
int max_queries;
vector<int> query(vector<int> &v) {
	assert(max_queries);
	max_queries--;
	if (debug) {
		vector<int> res = {v[0]};
		rep(i, 1, v.size()) {
			if (perm[v[i]] > perm[res.back()]) {
				res.push_back(v[i]);
			}
		}
		return res;
	}
	cout << "? " << v.size() << ' ';
	for (int i : v) {
		cout << i + 1 << ' ';
	}
	cout << endl;
	cout.flush();
	int c;
	input(c);
	vector<int> res(c);
	arrput(res);
	rep(i, 0, c) {
		res[i]--;
	}
	return res;
}

void solve(vector<int> &dp, vector<int> &p, vector<vector<int>> &graph) {
	int m = graph.size();
	dp.clear();
	dp.resize(m, 1);
	p.clear();
	p.resize(m, -1);
	for (int i = m - 1; i >= 0; i--) {
		for (int j : graph[i]) {
			if (j < i) {
				continue;
			}
			if (dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
	}
}

bool check(vector<int> &res) {
	bool a = true, b = true;
	rep(i, 1, res.size()) {
		a &= perm[res[i]] > perm[res[i - 1]];
		b &= perm[res[i]] < perm[res[i - 1]];
	}
	return a or b;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int m = n * n + 1;
		max_queries = n;
		if (debug) {
			perm.resize(m);
			arrput(perm);
		}

		vector<bool> v(m, false);
		vector<vector<int>> graph(m), rev_graph(m);
		vector<int> res;
		rep(i, 0, n) {
			vector<int> a;
			rep(j, 0, m) {
				if (!v[j]) {
					a.push_back(j);
				}
			}
			vector<int> b = query(a);
			if (b.size() > n) {
				res = b;
				break;
			}

			int l = 0, p = -1;
			rep(j, 0, m) {
				if (v[j]) {
					continue;
				}

				if (l < b.size() and b[l] == j) {
					if (p != -1) {
						graph[p].push_back(j);
						rev_graph[j].push_back(p);
					}
					p = j;
					l++;
				}
				else {
					graph[j].push_back(p);
					rev_graph[p].push_back(j);
				}
			}

			l = b.size();
			for (int j = m - 1; j >= 0; j--) {
				if (v[j]) {
					continue;
				}

				if (l > 0 and b[l - 1] == j) {
					l--;
				}
				else if (l != b.size()) {
					graph[j].push_back(p);
					rev_graph[p].push_back(j);
				}
			}

			for (int j : b) {
				v[j] = true;
			}
		}

		if (!res.empty()) {
			while (res.size() > n + 1) {
				res.pop_back();
			}
			cout << "! ";
			for (int i : res) {
				cout << i + 1 << ' ';
			}
			cout << endl;
			continue;
		}

		vector<int> dp(m, 1), p(m, -1);
		solve(dp, p, graph);
		if (*max_element(dp.begin(), dp.end()) <= n) {
			solve(dp, p, rev_graph);
		}
		assert(*max_element(dp.begin(), dp.end()) > n);

		int u = max_element(dp.begin(), dp.end()) - dp.begin();
		res = {u};
		while (res.size() <= n) {
			u = p[u];
			res.push_back(u);
		}
		cout << "! ";
		for (int i : res) {
			cout << i + 1 << ' ';
		}
		cout << endl;
		if (debug) {
			assert(check(res));
		}
	}
}
