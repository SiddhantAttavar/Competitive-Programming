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

	int n, m, k;
	input(n, m, k);

	int x, y;
	input(x, y);

	vi a(n), b(m);
	arrput(a);
	arrput(b);

	sort(all(a));
	sort(all(b));

	vi c(n + 1, 0), d(m + 1, 0), e(m + 1, 0);
	rep(i, 0, n) {
		c[i + 1] = c[i] + a[i];
	}
	rep(i, 0, m) {
		d[i + 1] = d[i] + b[i];
		e[i + 1] = e[i] + (b[i] + k - 1) / k;
	}

	int res = 0, j = 0;
	for (int i = m; i >= 0; i--) {
		int t = e[i];
		if (t > y) {
			continue;
		}
		int z = x + y * k - d[i];
		while (j < n and z >= c[j + 1]) {
			j++;
		}
		res = max(res, i + j);
	}
	print(res);
}
