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
		int n, m, k;
		input(n, m, k);

		vi x;
		rep(i, 0, n) {
			int l, r;
			input(l, r);
			x.push_back(l);
			x.push_back(r + 1);
		}

		if (k == 0) {
			print(x[2 * n - 1] + 1);
			continue;
		}
		x.push_back(1e16);

		int c = 0, s = 1, res = -1;
		rep(i, 0, n) {
			c += max(0ll, min(s + m, x[2 * i + 1]) - max(s, x[2 * i]));
		}
		if (c == k) {
			print(s);
			continue;
		}

		while (s <= x[2 * n - 1]) {
			int i = upper_bound(all(x), s) - x.begin();
			int j = upper_bound(all(x), s + m) - x.begin();
			int d = (i % 2 ? -1 : 0) + (j % 2 ? 1 : 0);
			int z = min(x[i] - s, x[j] - s - m);
			if ((c < k and c + d * z >= k) or (c > k and c + d * z <= k)) {
				res = s + (k - c) / d;
				break;
			}
			c += d * z;
			s += z;
		}
		print(res);
		cout.flush();

		if (res != -1) {
			int z = 0;
			rep(i, 0, n) {
				z += max(0ll, min(res + m, x[2 * i + 1]) - max(res, x[2 * i]));
			}
			assert(z == k);
		}
	}
}
