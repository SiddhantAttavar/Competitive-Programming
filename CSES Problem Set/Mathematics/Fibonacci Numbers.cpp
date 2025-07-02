#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds; 
template<typename T> inline void input(T& x) {cin >> x;}
template<typename T, typename... S> inline void input(T& x, S&... args) {cin >> x; input(args ...);}
template<typename T> inline void print(T x) {cout << x << '\n';}
template<typename T, typename... S> inline void print(T x, S... args) {cout << x << ' '; print(args ...);}
template<typename T> inline void dbg(T x) {cerr << x << '\n';}
template<typename T, typename... S> inline void dbg(T x, S... args) {cerr << x << ", "; dbg(args ...);}
#define debug(...) cerr << #__VA_ARGS__ << ": "; dbg(__VA_ARGS__);
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define arrput(l) for (auto &i : l) {cin >> i;}
#define arrprint(l) for (auto i : l) {cout << i << ' ';} cout << '\n'
#define setup() ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> 
const int MOD = (int) 1e9 + 7; //998244353;

array<int, 4> mat_mul(array<int, 4> a, array<int, 4> b) {
	return {
		(a[0] * b[0] + a[1] * b[2]) % MOD,
		(a[0] * b[1] + a[1] * b[3]) % MOD,
		(a[2] * b[0] + a[3] * b[2]) % MOD,
		(a[2] * b[1] + a[3] * b[3]) % MOD
	};
}

array<int, 4> mat_pow(array<int, 4> a, int b) {
	array<int, 4> res = {1, 0, 0, 1};
	while (b) {
		if (b & 1) {
			res = mat_mul(res, a);
		}
		a = mat_mul(a, a);
		b >>= 1;
	}
	return res;
}

int32_t main() {
	setup();

	int n;
	input(n);

	if (n <= 1) {
		print(n);
		return 0;
	}

	array<int, 4> res = mat_pow({0, 1, 1, 1}, n - 1);
	print(res[3]);
}
