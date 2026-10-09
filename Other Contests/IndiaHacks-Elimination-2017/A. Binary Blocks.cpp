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
// #define int long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) (x.size()))
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
typedef vector<int> vi; typedef pair<int, int> pii;
const int MOD = (int) 1e9 + 7; //998244353;
inline int mpow(int a, int b) {int x = 1; for (; b; a = a * a % MOD, b >>= 1) {if (b & 1) {x = x * a % MOD;}} return x;};
inline int mdiv(int a, int b) {return a * mpow(b, MOD - 2) % MOD;};

const int N = 6000;
int a[N][N];

int calc(int n, int m, int p) {
	int res = 0;
	for (int i = 0; i < n; i += p) {
		for (int j = 0; j < m; j += p) {
			int c = a[i + p][j + p] - a[i][j + p] - a[i + p][j] + a[i][j];
			res += min(c, p * p - c);
		}
	}
	return res;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	rep(i, 0, n) {
		string s;
		input(s);
		rep(j, 0, m) {
			a[i + 1][j + 1] = s[j] == '1';
		}
	}

	rep(i, 0, 2 * max(n, m)) {
		rep(j, 0, 2 * max(n, m)) {
			a[i + 1][j + 1] += a[i][j + 1] + a[i + 1][j] - a[i][j];
		}
	}

	int res = n * m;
	rep(i, 2, max(n, m) + 1) {
		bool flag = true;
		rep(j, 2, i) {
			flag = flag and (i % j > 0);
		}
		if (flag) {
			res = min(res, calc(n, m, i));
		}
	}
	print(res);
}
