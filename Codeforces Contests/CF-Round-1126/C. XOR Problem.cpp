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

vi gray(int k) {
	if (k == 1) {
		return {0, 1};
	}
	vi x = gray(k - 1);
	vi y = x;
	reverse(all(x));
	rep(i, 0, 1 << (k - 1)) {
		x[i] |= 1 << (k - 1);
	}
	y.insert(y.end(), all(x));
	return y;
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		int k = 63 - __builtin_clzll(n);
		vi x = gray(k + 2);
		rep(i, 1 << (k + 1), 2 << (k + 1)) {
			x[i] ^= 1 << (k + 1);
		}

		print(sz(x) - 1);
		for (int i = (2 << (k + 1)) - 1; i > 0; i--) {
			x[i] ^= x[i - 1];
		}
		x.erase(x.begin());
		arrprint(x);
	}
}
