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
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi x(3 * n);
		arrput(x);
		sort(all(x));
		reverse(all(x));

		vi p(3 * n + 1);
		rep(i, 0, 3 * n) {
			p[i + 1] = p[i] + x[i];
		}

		int res = 0;
		rep(a, 0, n + 1) {
			int l = 1, r = n - a, b = 0;
			while (l <= r) {
				int m = (l + r) / 2;
				if (x[a + 2 * m - 2] + x[a + 2 * m - 1] >= 3 * x[3 * n - 2 * a - m]) {
					b = m;
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			res = max(res, 2 * p[a] + p[a + 2 * b] + 3 * p[3 * n - 2 * a - b]);
		}
		print(res);
	}
}
