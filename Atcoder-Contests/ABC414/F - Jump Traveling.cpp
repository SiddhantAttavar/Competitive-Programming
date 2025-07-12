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
// #define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

const int N = 2e5;
vector<int> tree_adj[N];
vector<int> graph[N * 20];
int p[N][20];
int d[N * 20];

void dfs(int u, int k) {
	for (int v : tree_adj[u]) {
		if (v == p[u][0]) {
			continue;
		}

		p[v][0] = u;
		rep(i, 1, k) {
			p[v][i] = p[u][i - 1];
		}

		rep(i, 0, k - 1) {
			if (p[v][i] == -1) {
				break;
			}
			rep(j, 0, k) {
				graph[k * v + j].push_back(k * p[v][i] + (i + 1 + j) % k);
				graph[k * p[v][i] + (i + 1 + j) % k].push_back(k * v + j);
			}
		}

		dfs(v, k);
	}
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, k;
		input(n, k);

		rep(i, 0, n) {
			tree_adj[i].clear();
			graph[i].clear();
			fill(p[i], p[i] + k, -1);
		}

		rep(i, 0, n - 1) {
			int u, v;
			input(u, v);
			tree_adj[u - 1].push_back(v - 1);
			tree_adj[v - 1].push_back(u - 1);
		}

		if (k > 1) {
			dfs(0, k);
		}

		fill(d, d + n * k, -1);
		queue<int> q;
		q.push(0);
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();
			q.pop();

			if (k > 1) {
				for (int v: graph[u]) {
					if (d[v] == -1) {
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}
			else {
				for (int v: tree_adj[u]) {
					if (d[v] == -1) {
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}
		}

		if (k == 1) {
			rep(i, 1, n) {
				cout << d[k * i] << ' ';
			}
		}
		else {
			rep(i, 1, n) {
				cout << (d[k * i] == -1 ? -1 : d[k * i] / 2) << ' ';
			}
		}
		cout << endl;
	}
}
