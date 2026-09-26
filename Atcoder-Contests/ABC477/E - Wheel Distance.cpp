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
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

int32_t main() {
	setup();

	int n, q;
	input(n, q);

	vi a(n), b(n);
	arrput(a);
	arrput(b);

	vector<vector<pii>> graph(n + 1);
	rep(i, 0, n) {
		graph[i].push_back({(i + 1) % n, a[i]});
		graph[(i + 1) % n].push_back({i, a[i]});
		graph[i].push_back({n, b[i]});
		graph[n].push_back({i, b[i]});
	}

	vi d(n + 1, 1e18);
	d[n] = 0;
	std::priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, n});
	while (!pq.empty()) {
		auto [x, u] = pq.top();
		pq.pop();

		for (auto [v, w] : graph[u]) {
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}

	vi p(n + 1);
	rep(i, 0, n) {
		p[i + 1] = p[i] + a[i];
	}

	while (q--) {
		int s, t;
		input(s, t);

		s--;
		t--;

		if (s > t) {
			swap(s, t);
		}

		if (t == n) {
			print(d[s]);
			continue;
		}

		print(min({d[s] + d[t], p[t] - p[s], p[n] - p[t] + p[s]}));
	}
}
