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
		int n, m;
		input(n, m);

		vector<bool> a(n, false);
		vector<array<int, 4>> p(m);
		vector<int> x(m);
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);
			u--;
			v--;
			p.push_back({i, u, v, w});
			a[u] = !a[u];
			a[v] = !a[v];
			x[i] = w;
		}

		UF d(n);
		vector<bool> b = a;
		vector<int> q, l;
		for (auto [i, u, v, w] : p) {
			int x = d.find(u);
			int y = d.find(v);
			if (!d.join(u, v)) {
				continue;
			}
			l.push_back(i);
			if (b[x] and b[y]) {
				q.push_back(i);
			}
			int z = d.find(u);
			b[z] = b[x] ^ b[y];
		}

		int res = accumulate(x.begin(), x.end(), 0ll);
		// for (int i = m - 2; i >= 0; i--) {
		// 	x[i] = min(x[i], x[i + 1]);
		// }
		for (int i : q) {
			res += x[i];
		}
		print(res);
	}
}
