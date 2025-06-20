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

void dfs(int l, int r, int x, int y, vector<int> &a, vector<int> &v, vector<int> &c) {
	if (l > r) {
		return;
	}
	int k = a[l];
	if (l == r) {
		c.push_back(k + 1);
		return;
	}

	int i = v[k];
	int n = i - x;
	dfs(l + 1, l + n, x, i - 1, a, v, c);
	dfs(l + n + 1, r, i + 1, y, a, v, c);
	c.push_back(k + 1);
}

int32_t main() {
	setup();

	int n;
	input(n);

	vector<int> a(n), b(n);
	arrput(a);
	arrput(b);

	vector<int> v(n);
	rep(i, 0, n) {
		a[i]--;
		b[i]--;
		v[b[i]] = i;
	}

	vector<int> c;
	dfs(0, n - 1, 0, n - 1, a, v, c);
	arrprint(c);
}
