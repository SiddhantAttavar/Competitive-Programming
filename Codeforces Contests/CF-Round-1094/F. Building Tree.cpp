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
	vi e, f;
	UF(int n) : e(n, -1), f(n, false) {}
	void set(int x) {f[x] = true;}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		f[a] |= f[b];
		return true;
	}
};

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m, q;
		input(n, m, q);

		vector<vector<pii>> edges(m + 1);
		rep(i, 0, m) {
			int u, v, w;
			input(u, v, w);
			edges[w].push_back({u - 1, v - 1});
		}

		UF d(n), e(n);
		vi c(q);
		arrput(c);
		rep(i, 0, q) {
			d.set(c[i] - 1);
		}
		rep(i, 1, m + 1) {
			for (auto [u, v] : edges[i]) {
				if (d.f[u] and d.f[v]) {
					d.join(u, v);
				}
			}
		}

		int res = 0;
		rep(i, 0, m + 1) {
			for (auto [u, v] : edges[i]) {
				if (d.f[u] and d.f[v] and !e.sameSet(u, v)) {
					res += i + 1;
					d.join(u, v);
				}
			}
		}

		bool flag = true;
		rep(i, 1, n) {
			if (d.f[i] and !d.sameSet(i, c[0] - 1)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			print(res);
		}
		else {
			print(-1);
		}
	}
}
