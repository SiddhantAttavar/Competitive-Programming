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

bool check(vi &res, int n) {
	vi v(2 * n + 1, true);
	v[0] = false;
	v[1] = false;
	for (int x : res) {
		assert(x >= 2 and x <= 2 * n);
		v[x] = false;
		vi w(2 * n + 1, false);
		rep(i, 2, 2 * n + 1) {
			if (v[i] and i >= 4) {
				w[i - 2] = true;
			}
			if (v[i] and i < 2 * n) {
				w[i + 1] = true;
			}
		}
		v = w;
	}
	return accumulate(all(v), 0ll) == 0;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi res;
		rep(i, 0, 3) {
			int j = (i + sz(res)) % 3;
			for (int c = 2 * n - (2 * n - j + 3) % 3; c >= 2; c -= 2) {
				res.push_back(c);
			}
		}
		print(sz(res));
		arrprint(res);
		cout.flush();
		assert(check(res, n));
	}
}
