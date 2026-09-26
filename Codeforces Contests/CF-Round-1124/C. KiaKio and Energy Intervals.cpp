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

void solve(vi a, int &res) {
	if (sz(a) <= 1) {
		return;
	}
	int n = sz(a), k = *max_element(all(a));
	if (k < res) {
		return;
	}
	vi p(n + 1, 0);
	rep(i, 0, n) {
		p[i + 1] = p[i] ^ (a[i] & k);
	}

	set<int> s;
	int x = -1;
	rep(i, 0, n) {
		if (a[i] == k) {
			rep(j, x + 1, i) {
				res = max(res, p[i + 1] ^ p[j]);
			}
			rep(j, x + 1, i + 1) {
				s.insert(p[j]);
			}
			x = i;
		}
		else if (sz(s) < k - res) {
			for (int j : s) {
				res = max(res, p[i + 1] ^ j);
			}
		}
		else {
			rep(j, 0, k - res) {
				if ((k & j) == j and s.count(p[i + 1] ^ j ^ k)) {
					res = max(res, k ^ j);
				}
			}
		}
	}

	vi b;
	rep(i, 0, n) {
		if (a[i] == k) {
			solve(b, res);
			b.clear();
		}
		else {
			b.push_back(a[i]);
		}
	}
	solve(b, res);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n);
		arrput(a);

		int res = 0;
		solve(a, res);
		print(res);
	}
}
