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

vi get(int u, vector<vi> &graph) {
	vi d(sz(graph), 1e18);
	d[u] = 0;
	queue<int> q;
	q.push(u);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v : graph[u]) {
			if (d[v] == 1e18) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vi x(m), y(m);
	arrput(x);
	arrput(y);

	vector<vi> graph(n), rev_graph(n);
	rep(i, 0, m) {
		graph[x[i] - 1].push_back(y[i] - 1);
		rev_graph[y[i] - 1].push_back(x[i] - 1);
	}

	string s;
	input(s);

	int u;
	input(u);
	u--;

	vi p = get(u, graph), q = get(u, rev_graph);
	int res = 1e18;
	rep(i, 0, n) {
		if (s[i] == '1') {
			res = min(res, p[i] + q[i]);
		}
	}
	if (res == 1e18) {
		print(-1);
	}
	else {
		print(res);
	}
}
