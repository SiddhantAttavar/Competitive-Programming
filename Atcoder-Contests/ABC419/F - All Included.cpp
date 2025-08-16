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
const int MOD = 998244353;

void dfs(int u, vector<vector<int>> &graph, vector<string> &s, string &c, vector<vector<int>> &temp) {
	rep(i, 0, 26) {
		if (temp[u][i] != -1) {
			c += i + 'a';
			dfs(temp[u][i], graph, s, c, temp);
			c.pop_back();
			continue;
		}

		string t = c;
		t += i + 'a';
		while (!t.empty()) {
			t.erase(t.begin());
			int v = 0;
			for (char c : t) {
				v = temp[v][c - 'a'];
				if (v == -1) {
					break;
				}
			}
			if (v != -1) {
				graph[u][i] = v;
				break;
			}
		}

		if (graph[u][i] == -1) {
			graph[u][i] = 0;
		}
	}
}

int32_t main() {
	setup();

	int n, l;
	input(n, l);

	vector<string> s(n);
	arrput(s);
	s.erase(unique(s.begin(), s.end()), s.end());
	sort(s.begin(), s.end(), [](string a, string b) {
		return a.size() < b.size();
	});

	vector<string> t;
	rep(i, 0, n) {
		bool flag = true;
		rep(j, i + 1, n) {
			if (s[j].find(s[i]) != string::npos) {
				flag = false;
				break;
			}
		}
		if (flag) {
			t.push_back(s[i]);
		}
	}
	s = t;
	n = t.size();

	vector<vector<int>> graph(1, vector<int>(26, -1));
	vector<int> v = {-1};
	rep(i, 0, n) {
		int u = 0;
		for (char c : s[i]) {
			if (graph[u][c - 'a'] == -1) {
				graph.push_back(vector<int>(26, -1));
				v.push_back(-1);
				graph[u][c - 'a'] = graph.size() - 1;
			}
			u = graph[u][c - 'a'];
		}
		v[u] = i;
	}

	string c;
	vector<vector<int>> temp = graph;
	dfs(0, graph, s, c, temp);

	vector<vector<int>> dp(1 << n, vector<int>(graph.size(), 0));
	dp[0][0] = 1;
	rep(i, 0, l) {
		vector<vector<int>> ndp(1 << n, vector<int>(graph.size(), 0));
		rep(x, 0, 1 << n) {
			rep(u, 0, graph.size()) {
				rep(c, 0, 26) {
					int w = graph[u][c];
					int y = v[w] == -1 ? x : x | (1 << v[w]);
					ndp[y][w] = (ndp[y][w] + dp[x][u]) % MOD;
				}
			}
		}
		dp = ndp;
	}
	print(accumulate(dp.back().begin(), dp.back().end(), 0ll) % MOD);
}
