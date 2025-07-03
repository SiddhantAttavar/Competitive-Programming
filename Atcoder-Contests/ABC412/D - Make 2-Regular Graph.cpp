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

bool check(vector<int> &b) {
	rep(i, 0, b.size()) {
		if (__builtin_popcount(b[i]) != 2) {
			return false;
		}
	}
	return true;
}

int solve(int i, vector<int> &a, vector<int> &b) {
	int res = a.size() * (a.size() - 1) / 2;
	if (i == a.size()) {
		if (!check(b)){
			return res;
		}
		int x = 0, y = 0;
		rep(j, 0, a.size()) {
			y += __builtin_popcount(a[j] ^ b[j]);
			x += (a[j] ^ b[j]) >> i & 1;
		}
		return (y + x) / 2;
	}

	if (__builtin_popcount(b[i]) == 1) {
		rep(j, i + 1, a.size()) {
			b[i] ^= 1 << j;
			b[j] ^= 1 << i;
			res = min(res, solve(i + 1, a, b));
			b[i] ^= 1 << j;
			b[j] ^= 1 << i;
		}
	}
	else if (__builtin_popcount(b[i]) == 0) {
		rep(j, i + 1, a.size()) {
			b[i] ^= 1 << j;
			b[j] ^= 1 << i;
			rep(k, j + 1, a.size()) {
				b[i] ^= 1 << k; 
				b[k] ^= 1 << i;
				res = min(res, solve(i + 1, a, b));
				b[i] ^= 1 << k; 
				b[k] ^= 1 << i;
			}
			b[i] ^= 1 << j;
			b[j] ^= 1 << i;
		}
	}
	else {
		return solve(i + 1, a, b);
	}
	return res;
}

int32_t main() {
	setup();

	int n, m;
	input(n, m);

	vector<int> a(n, 0), b(n, 0);
	rep(i, 0, m) {
		int u, v;
		input(u, v);
		u--;
		v--;

		a[u] |= 1 << v;
		a[v] |= 1 << u;
	}

	print(solve(0, a, b));
}
