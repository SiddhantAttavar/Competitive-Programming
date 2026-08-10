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
const int MOD = 998244353;

int mpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % MOD;
		}
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int mdiv(int a, int b) {
	return a * mpow(b, MOD - 2) % MOD;
}

const int N = 2e6;
vi fact(N + 1, 1);

int get(int n, int r) {
	if (r == 0) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	return mdiv(fact[n - 1], fact[n - r] * fact[r - 1] % MOD);
}

int32_t main() {
	rep(i, 2, N + 1) {
		fact[i] = i * fact[i - 1] % MOD;
	}
	setup(); int tc; input(tc); while (tc--) {
		int n;
		input(n);

		string s;
		input(s);

		int a = count(all(s), '0'), b = n - a, c = 0;
		rep(i, 1, n) {
			c += s[i] != s[i - 1];
		}

		int x = 0, y = 0;
		if (c % 2) {
			x = (c + 1) / 2;
			y = (c + 1) / 2;
		}
		else if (s[0] == '0') {
			x = c / 2 + 1;
			y = c / 2;
		}
		else {
			x = c / 2;
			y = c / 2 + 1;
		}

		print(get(a, x) * get(b, y) % MOD);
	}
}
