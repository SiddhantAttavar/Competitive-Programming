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
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;

void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step]; tie(u, v) =
				// inv ? pii(v - u, u) : pii(v, u + v); // AND
				inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				// pii(u + v, u - v);                   // XOR /// include-line
		}
	}
	// if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1); return a;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vi w(n), c(m);
	arrput(w);
	arrput(c);

	vi dp(1 << n, false);
	dp[0] = true;
	rep(i, 0, m) {
		vi a(1 << n, false);
		rep(j, 0, 1 << n) {
			int x = 0;
			rep(k, 0, n) {
				if (j >> k & 1) {
					x += w[k];
				}
			}
			a[j] = x <= c[i];
		}
		dp = conv(dp, a);
		rep(j, 0, 1 << n) {
			dp[j] = dp[j] > 0;
		}
	}
	if (dp.back()) {
		print("Yes");
	}
	else {
		print("No");
	}
}
