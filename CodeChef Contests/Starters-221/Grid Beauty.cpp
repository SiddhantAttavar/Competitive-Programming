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

int dist(int x, int y, int a, int b) {
	return (abs(x - a) + 1) * (abs(y - b) + 1);
}

int cmb(int a, int b, int m) {
	return a * m + b;
}

bool check(vector<vi> &a, int x) {
	int n = sz(a), m = sz(a[0]);
	UF u(n * m);
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (dist(i, j, 0, 0) >= x) {
				u.join(cmb(i, j, m), cmb(0, 0, m));
			}
			if (dist(i, j, n - 1, 0) >= x) {
				u.join(cmb(i, j, m), cmb(n - 1, 0, m));
			}
			if (dist(i, j, 0, m - 1) >= x) {
				u.join(cmb(i, j, m), cmb(0, m - 1, m));
			}
			if (dist(i, j, n - 1, m - 1) >= x) {
				u.join(cmb(i, j, m), cmb(n - 1, m - 1, m));
			}
		}
	}
	rep(i, 0, n) {
		rep(j, 0, m) {
			if (!u.sameSet(a[i][j], cmb(i, j, m))) {
				return false;
			}
		}
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vector<vi> a(n, vi(m));
		rep(i, 0, n) {
			arrput(a[i]);
		}

		rep(i, 0, n) {
			rep(j, 0, m) {
				a[i][j]--;
			}
		}
		
		int l = 1, r = n * m + 1, res = 1;
		while (l <= r) {
			int m = (l + r) / 2;
			if (check(a, m)) {
				res = m;
				l = m + 1;
			}
			else {
				r = m - 1;
			}
		}
		print(res);
	}
}
