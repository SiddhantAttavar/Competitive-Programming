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

int32_t main() {
	const int N = 40;
	setup(); int tc; input(tc); while (tc--) {
		int n, q;
		input(n, q);

		vector<int> a(n);
		arrput(a);
		
		int z = accumulate(a.begin(), a.end(), 0ll);
		vector<int> res(N, 1e18);
		int x = 0;
		for (int i : a) {
			x |= i;
		}
		int c = __builtin_popcount(x);
		rep(i, 0, c + 1) {
			res[i] = 0;
		}

		rep(i, 1, N) {
			vector<int> b = a;
			vector<int> v(N, 0);
			for (int i : b) {
				rep(j, 0, N) {
					v[j] += i >> j & 1;
				}
			}

			for (int j = i - 1; j >= 0; j--) {
				if (v[j]) {
					continue;
				}

				int u = 0;
				int z = (1ll << j) - 1;
				rep(k, 1, n) {
					if ((b[k] & z) > (b[u] & z)) {
						u = k;
					}
				}
				rep(k, 0, j) {
					v[k] -= b[u] >> k & 1;
				}
				b[u] &= ~z;
				b[u] |= 1ll << j;
				v[j]++;
			}

			int c = 0;
			rep(j, 0, N) {
				c += v[j] > 0;
			}

			int y = accumulate(b.begin(), b.end(), 0ll) - z;
			rep(j, 0, c + 1) {
				res[j] = min(res[j], y);
			}
		}

		while (q--) {
			int x;
			input(x);

			int z = 0;
			rep(i, 0, N) {
				if (res[i] <= x) {
					z = i;
				}
			}
			print(z);
		}
	}
}
