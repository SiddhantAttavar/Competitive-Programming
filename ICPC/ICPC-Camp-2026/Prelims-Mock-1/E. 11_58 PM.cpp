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

		vi x(n), y(n);
		x[0] = -1;
		rep(i, 1, n) {
			x[i] = s[i] == s[i - 1] ? x[i - 1] : i - 1;
		}
		y[n - 1] = n;
		for (int i = n - 2; i >= 0; i--) {
			y[i] = s[i] == s[i + 1] ? y[i + 1] : i + 1;
		}

		vector<vi> a(n, vi(26, 1)), b(n, vi(26, 1));
		a[0][s[0] - 'a']--;
		b[n - 1][s[n - 1] - 'a']--;
		rep(i, 1, n) {
			a[i] = a[i - 1];
			rep(j, 0, 26) {
				a[i][j]++;
			}
			a[i][s[i] - 'a']--;
		}
		for (int i = n - 2; i >= 0; i--) {
			b[i] = b[i + 1];
			rep(j, 0, 26) {
				b[i][j]++;
			}
			b[i][s[i] - 'a']--;
		}

		int res = 1;
		rep(i, 0, n) {
			if (i and s[i] == s[i - 1]) {
				continue;
			}
			res += x[i] == -1 ? 0 : a[x[i]][s[i] - 'a'];
			res += y[i] == n ? 0 : b[y[i]][s[i] - 'a'];
		}

		rep(i, 0ll, n - 1) {
			if (s[i] == s[i + 1]) {
				continue;
			}
			int j = i + 1;
			while (j < n - 1 and s[j + 1] == s[i + (j + 1 - i) % 2]) {
				j++;
			}
			int l = j - i + 1;
			res -= (l / 2) * ((l + 1) / 2);
			i = j - 1;
		}

		print(res);
	}
}
