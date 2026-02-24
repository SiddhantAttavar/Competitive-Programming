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
const int MOD = 998244353;

int32_t main() {
	const int N = 3e5;
	vi pow2(N + 1, 1);
	rep(i, 1, N + 1) {
		pow2[i] = pow2[i - 1] * 2 % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int res = 0, d = 0;
		int x = 0, y = 0, z = 0;
		rep(i, 0, n) {
			int k = (x + y + (d > 0)) % MOD;
			if (s[i] == '(') {
				d++;
				// cout << pow2[i] << ' ';
				res = (res + pow2[i]) % MOD;
				if (d > 1) {
					x = (x + k) % MOD;
				}
				else {
					x = 0;
				}
			}
			else {
				d--;
				// cout << k << ' ';
				res = (res + k) % MOD;
				y = (y + k) % MOD;
				if (d <= 1) {
					x = 0;
				}
			}
			// print(x, y);
		}
		// cout << endl;
		print(res);
	}
}
