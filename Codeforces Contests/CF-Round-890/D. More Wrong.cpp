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

int query(int l, int r) {
	if (l == r) {
		return 0;
	}
	print('?', l + 1, r + 1);
	cout.flush();
	int x;
	input(x);
	return x;
}

int solve(int l, int r) {
	if (l == r) {
		return l;
	}

	int m = (l + r) / 2;
	int x = solve(l, m), y = solve(m + 1, r);
	if (query(x, r) == query(x + 1, r) + (r - x)) {
		return x;
	}
	return y;
}

int32_t main() {
	int tc; input(tc); while (tc--) {
		int n;
		input(n);

		print('!', solve(0, n - 1) + 1);
	}
}
