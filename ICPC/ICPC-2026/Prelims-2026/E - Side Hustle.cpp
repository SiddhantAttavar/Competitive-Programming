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
		int n, c;
		input(n, c);

		vi p(n), a(n);
		arrput(p);
		arrput(a);
		rep(i, 0, n) {
			p[i]--;
		}

		vi vis(n, false);
		int res = 0;
		rep(i, 0, n) {
			if (vis[i]) {
				continue;
			}

			int u = p[i], s = a[i], l = 1, y = max(0ll, a[i] - c);
			vis[i] = true;
			while (u != i) {
				y += max(0ll, a[u] - c);
				s += a[u];
				vis[u] = true;
				l++;
				u = p[u];
			}

			if (l == 1) {
				res += s;
			}
			else {
				res += max(y, s - (l - 1) * c);
			}
		}
		print(res);
	}
}
