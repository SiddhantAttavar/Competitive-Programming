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

int get(int x, vi &p, vi &v) {
	x = min(x, v.back());
	int i = lower_bound(all(v), x) - v.begin();
	int res = i == -1 ? 0 : p[i];
	return res + (v.back() / v[i]) * (x - v[i]);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int s, q;
		input(s, q);

		vi v;
		for (int i = 1; i * i <= s; i++) {
			if (s % i == 0) {
				v.push_back(i);
				if (i != s / i) {
					v.push_back(s / i);
				}
			}
		}
		sort(all(v));

		vi p(sz(v));
		p[0] = s;
		rep(i, 1, sz(v)) {
			p[i] = p[i - 1] + s / v[i] * (v[i] - v[i - 1]);
		}
		p.push_back(p.back());

		while (q--) {
			int x, y;
			input(x, y);

			x = min(x, s);
			y = min(y, s);

			int l = 1, r = x, u = 0;
			while (l <= r) {
				int m = (l + r) / 2;
				int i = *lower_bound(all(v), m);
				if (s / i >= y) {
					u = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}

			print(y * u + get(x, p, v) - get(u, p, v));
		}
	}
}
