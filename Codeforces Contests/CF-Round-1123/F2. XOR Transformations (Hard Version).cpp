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
		int n, q;
		input(n, q);

		vi a(n);
		arrput(a);

		sort(all(a));
		vi res = {a[n - 1] - a[0]};
		rep(i, 0, 60) {
			vi b;
			int k = 0;
			rep(j, 0, 31) {
				int c = 0, v = 0;
				rep(u, 1, n) {
					if ((a[u] >> j) != (a[u - 1] >> j)) {
						v = u;
					}
					c += u - v;
				}
				if (c >= n) {
					k = j;
					break;
				}
			}
			if (k == 0) {
				break;
			}

			int v = 0;
			rep(u, 1, n) {
				if ((a[u] >> k) != (a[u - 1] >> k)) {
					v = u;
				}
				rep(w, v, u) {
					b.push_back(a[w] ^ a[u]);
				}
			}

			sort(all(b));
			a = vi(b.begin(), b.begin() + n);
			res.push_back(a[n - 1] - a[0]);
		}

		while (q--) {
			int i;
			input(i);
			print(i >= sz(res) ? 0 : res[i]);
		}
	}
}
