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
	setup();

	int n, q;
	input(n, q);

	string s;
	input(s);

	vector<array<int, 3>> p(n, {0, 0, 0});
	rep(i, 0, n - 1) {
		p[i + 1] = p[i];
		p[i + 1][0] += s[i] == '0' and s[i + 1] == '0';
		p[i + 1][1] += s[i] == '1' and s[i + 1] == '1';
		p[i + 1][2] += s[i] == '0' and s[i + 1] == '1';
	}

	while (q--) {
		int l, r;
		input(l, r);

		l--;
		r--;

		if (l == r) {
			print(3);
			continue;
		}

		int a = p[r][0] - p[l][0], b = p[r][1] - p[l][1], c = p[r][2] - p[l][2];
		a += s[r] == '0' and s[l] == '0';
		b += s[r] == '1' and s[l] == '1';
		c += s[r] == '0' and s[l] == '1';

		int u = c, v = max({a, b, c}), res = -1;
		while (u <= v) {
			int m = (u + v) / 2;
			if (c + max(0ll, a - m) + max(0ll, b - m) <= m) {
				res = m;
				v = m - 1;
			}
			else {
				u = m + 1;
			}
		}
		print(4 * res - a - b - 2 * c);
	}
}
