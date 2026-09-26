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

		string s;
		input(s);

		bool flag = s[0] == '0';
		rep(i, 0, n - 1) {
			flag = flag or (s[i] == '0' and s[i + 1] == '0');
		}
		if (flag) {
			print(-1);
			continue;
		}

		array<bool, 5> a = {false, false, true, false, false};
		for (char c : s) {
			array<bool, 5> b;
			b[0] = a[1];
			b[4] = a[3];
			rep(j, 1, 4) {
				b[j] = a[j - 1] or a[j + 1];
			}
			if (c == '0') {
				b[0] = b[1] = b[3] = b[4] = false;
			}
			else if (c == '-') {
				b[2] = b[3] = b[4] = false;
			}
			else {
				b[0] = b[1] = b[2] = false;
			}
			a = b;
		}

		if (a[0] or a[1] or a[2] or a[3] or a[4]) {
			print(1);
			continue;
		}

		array<bool, 7> f = {false, false, false, true, false, false, false};
		for (char c : s) {
			array<bool, 7> g;
			g[0] = f[1] or f[2];
			g[1] = f[0] or f[2] or f[3];
			g[5] = f[3] or f[4] or f[6];
			g[6] = f[4] or f[5];
			rep(j, 2, 5) {
				g[j] = f[j - 2] or f[j - 1] or f[j + 1] or f[j + 2];
			}
			if (c == '0') {
				g[0] = g[1] = g[2] = g[4] = g[5] = g[6] = false;
			}
			else if (c == '-') {
				g[3] = g[4] = g[5] = g[6] = false;
			}
			else {
				g[0] = g[1] = g[2] = g[3] = false;
			}
			f = g;
		}

		if (f[0] or f[1] or f[2] or f[3] or f[4] or f[5] or f[6]) {
			print(2);
		}
		else {
			print(3);
		}
	}
}
