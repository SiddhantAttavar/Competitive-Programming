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
#define vi vector<int>
#define pii pair<int, int>
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	int s, t, c;
	input(s, t, c);
	s--;
	t--;

	vector<vector<pii>> graph(n);
	rep(i, 1, m) {
		int u, v, w;
		input(u, v, w);
		graph[u - 1].push_back({v - 1, w});
	}

	vi d(n, 1e18);
	d[t] = 0;
	std::priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, t});
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		if (x != d[u]) {
			continue;
		}

		if (u == s) {
			print(x + c);
			return 0;
		}

		for (auto [v, w] : graph[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	print(-1);
}
