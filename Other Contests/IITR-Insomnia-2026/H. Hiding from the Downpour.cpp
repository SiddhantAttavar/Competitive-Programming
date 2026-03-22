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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, k;
		input(n, m, k);

		int a, b;
		input(a, b);

		int s;
		input(s);

		vi l(s);
		arrput(l);

		a--;
		b--;

		rep(i, 0, s) {
			l[i]--;
		}
		l.push_back(a);
		l.push_back(b);

		vector<vector<pii>> graph(n);
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);

			graph[u - 1].push_back({v - 1, w});
			graph[v - 1].push_back({u - 1, w});
		}

		vi d(n, 2e18), c(n, -1);
		UF z(n);
		std::priority_queue<pii, vector<pii>, greater<pii>> pq;
		for (int i : l) {
			d[i] = 0;
			pq.push({0, i});
			c[i] = i;
		}
		while (!pq.empty()) {
			auto [x, u] = pq.top();
			pq.pop();

			if (x != d[u]) {
				continue;
			}

			for (auto [v, w] : graph[u]) {
				if (d[u] + w > k) {
					continue;
				}
				if (d[u] + d[v] + w <= k) {
					z.join(u, v);
				}
				if (d[v] > d[u] + w) {
					d[v] = d[u] + w;
					c[v] = c[u];
					z.join(u, c[u]);
					pq.push({d[v], v});
				}
			}
		}

		if (z.sameSet(a, b)) {
			print("YES");
		}
		else {
			print("NO");
		}
	}
}
