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
	setup();

	int n, m, q;
	input(n, m, q);

	vector<pair<int, int>> e(m);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		e[i] = {u - 1, v - 1};
	}

	vector<int> l(q, 0), r(q, m - 1), res(q, -2), a(q), b(q);
	rep(i, 0, q) {
		input(a[i], b[i]);
		a[i]--;
		b[i]--;
		if (a[i] == b[i]) {
			res[i] = -1;
			r[i] = -1;
		}
	}
	rep(j, 0, 30) {
		vector<vector<int>> v(m);
		rep(i, 0, q) {
			if (l[i] <= r[i]) {
				v[(l[i] + r[i]) / 2].push_back(i);
			}
		}

		UF d(n);
		rep(i, 0, m) {
			d.join(e[i].first, e[i].second);

			for (int k : v[i]) {
				if (d.sameSet(a[k], b[k])) {
					res[k] = i;
					r[k] = i - 1;
				}
				else {
					l[k] = i + 1;
				}
			}
		}
	}
	rep(i, 0, q) {
		print(res[i] + 1);
	}
}
