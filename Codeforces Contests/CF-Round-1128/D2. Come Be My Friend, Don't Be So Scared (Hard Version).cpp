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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

bool check(vector<pii> &a, vector<pii> &b, int n) {
	vi d(n + 1, 0);
	for (auto [l, r] : a) {
		int x = rng();
		d[l] ^= x;
		d[r + 1] ^= x;
	}
	for (auto [l, r] : b) {
		int x = rng();
		d[l] ^= x;
		d[r + 1] ^= x;
	}
	rep(i, 0, n) {
		d[i + 1] ^= d[i];
	}
	set<int> s;
	rep(i, 0, n) {
		if (s.count(d[i])) {
			return false;
		}
		s.insert(d[i]);
	}
	return true;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n, m;
		input(n, m);

		vi d(n + 1, 0);
		vector<pii> e;
		while (m--) {
			int l, r;
			input(l, r);
			int x = rng();
			l--;
			r--;
			e.push_back({l, r});
			d[l] ^= x;
			d[r + 1] ^= x;
		}

		if (n == 1) {
			print(0);
			continue;
		}

		rep(i, 0, n) {
			d[i + 1] ^= d[i];
		}

		map<int, int> s;
		int x = 0, j = -1;
		vi l;
		rep(i, 0, n) {
			if (!s.count(d[i])) {
				s[d[i]] = x;
				continue;
			}
			if (s[d[i]] == x) {
				l.push_back(i);
				x++;
				j = i;
			}
			s[d[i]] = x;
		}

		vector<pii> res;
		if (sz(l) % 2) {
			l.push_back(n);
		}
		rep(i, 0, sz(l) / 2) {
			res.push_back({l[i], l[i + (sz(l) / 2)] - 1});
		}
		if (!check(res, e, n)) {
			res.push_back({j, n - 1});
		}

		print(sz(res));
		for (auto [a, b] : res) {
			print(a + 1, b + 1);
		}
		// cout.flush();
		// assert(check(res, e, n));
	}
}
