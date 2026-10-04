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

bool get(int i, int x, vi &a, vi &b) {
	return (
		(i == 0 or x <= a[i - 1] - b[i - 1] or x >= a[i - 1] + b[i - 1]) and
		(i == sz(a) - 1 or x <= a[i + 1] - b[i + 1] or x >= a[i + 1] + b[i + 1])
	);
}

bool check(int i, vi &a, vi &b) {
	if (i < 0 or i == sz(a)) {
		return 0;
	}
	return get(i, a[i] - b[i], a, b) or get(i, a[i] + b[i], a, b);
}

int32_t main() {
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		vi a(n), b(n);
		arrput(a);
		arrput(b);

		int c = 0;
		rep(i, 0, n) {
			c += check(i, a, b);
		}

		int q;
		input(q);
		while (q--) {
			int i, z;
			input(i, z);
			i--;

			c -= check(i - 1, a, b);
			c -= check(i, a, b);
			c -= check(i + 1, a, b);
			b[i] = z;
			c += check(i - 1, a, b);
			c += check(i, a, b);
			c += check(i + 1, a, b);

			if (c == n) {
				print("Yes");
			}
			else {
				print("No");
			}
		}
	}
}
